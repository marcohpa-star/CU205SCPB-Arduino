#include "CU205SCPB.h"
#include "CU205SCPB_Commands.h"
#include <string.h>
CU205SCPB::CU205SCPB(const uint8_t p[8],uint8_t wr,uint8_t cs){memcpy(_d,p,8);_wr=wr;_cs=cs;}

bool CU205SCPB::begin()
{
    for(int i=0;i<8;i++)
    {
        pinMode(_d[i],OUTPUT);
        digitalWrite(_d[i],LOW);
    }

    pinMode(_wr,OUTPUT);
    pinMode(_cs,OUTPUT);

    digitalWrite(_wr,HIGH);
    digitalWrite(_cs,HIGH);

    // Tempo de inicialização do controlador
    delay(500);

    _cursorPos = 0;

    return true;
}
void CU205SCPB::sendByte(uint8_t v){digitalWrite(_cs,LOW);for(uint8_t i=0;i<8;i++)digitalWrite(_d[i],bitRead(v,i));delayMicroseconds(2);digitalWrite(_wr,LOW);delayMicroseconds(2);digitalWrite(_wr,HIGH);digitalWrite(_cs,HIGH);delay(10);}

void CU205SCPB::clear()
{
    sendByte(CU205_CLR);      // CLR
    delay(100);

    sendByte(CU205_CR);      // CR

    _cursorPos = 0;

    delay(10);
}

void CU205SCPB::home()
{
    sendByte(CU205_CR);

    _cursorPos = 0;
}


void CU205SCPB::setCursor(uint8_t p)
{
    if(p>19)
        p=19;

    sendByte(CU205_ESC);
    sendByte('H');
    sendByte(p);

    _cursorPos=p;
}
void CU205SCPB::setBrightness(uint8_t v){sendByte(CU205_ESC);sendByte('L');sendByte(v);}

void CU205SCPB::cursorOff()
{
    sendByte(CU205_DC4);   // DC4
}

void CU205SCPB::cursorOn()
{
    sendByte(CU205_DC5);   // DC5
}

void CU205SCPB::backspace()
{
    sendByte(CU205_BS);

    if(_cursorPos>0)
        _cursorPos--;
}

void CU205SCPB::tab()
{
    sendByte(CU205_HT);   // HT
}

void CU205SCPB::carriageReturn()
{
    sendByte(CU205_CR);

    _cursorPos=0;
}

void CU205SCPB::autoReturnMode()
{
    sendByte(CU205_DC1);    // DC1
}

void CU205SCPB::overwriteMode()
{
    sendByte(CU205_DC2);    // DC2
}

void CU205SCPB::scrollMode()
{
    sendByte(CU205_DC3);    // DC3
}

size_t CU205SCPB::write(uint8_t c)
{
    if(c==10)
        return 1;

    if(c==13)
    {
        carriageReturn();
        return 1;
    }

    sendByte(c);

    if(_cursorPos < CU205_COLUMNS-1)
    _cursorPos++;
else
    _cursorPos = CU205_COLUMNS-1;

    return 1;
}


uint8_t CU205SCPB::getCursorPosition()
{
    return _cursorPos;
}



// IMPORTANTE:
// O controlador interno do CU205SCPB necessita de aproximadamente
// 500 ms após a energização antes de aceitar comandos.
// Sem essa espera, podem ocorrer perda de caracteres ou
// inicialização incompleta do display.
//delay(500);na linha begin()