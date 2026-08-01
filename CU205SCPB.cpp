#include "CU205SCPB.h"
#include "CU205SCPB_Commands.h"
#include <string.h>


// ==========================================================
// Construtor
// ==========================================================

CU205SCPB::CU205SCPB(const uint8_t p[8], uint8_t wr, uint8_t cs)
{
    memcpy(_d, p, 8);

    _wr = wr;
    _cs = cs;
}


// ==========================================================
// Inicialização
// ==========================================================

bool CU205SCPB::begin()
{
    // Configura barramento de dados D0-D7
    for(int i = 0; i < 8; i++)
    {
        pinMode(_d[i], OUTPUT);
        digitalWrite(_d[i], LOW);
    }

    // Configura sinais de controle
    pinMode(_wr, OUTPUT);
    pinMode(_cs, OUTPUT);

    // Estado inicial dos sinais
    digitalWrite(_wr, HIGH);
    digitalWrite(_cs, HIGH);

    // O controlador necessita de aproximadamente
    // 500 ms após a energização antes de aceitar comandos.
    // Sem esta espera podem ocorrer perda de caracteres
    // ou inicialização incompleta do display.
    delay(500);

    // Cursor inicia na posição 0
    _cursorPos = 0;

    return true;
}


// ==========================================================
// Comunicação interna
// ==========================================================

void CU205SCPB::sendByte(uint8_t value)
{
    // Ativa o display
    digitalWrite(_cs, LOW);

    // Coloca os 8 bits no barramento de dados
    for(uint8_t i = 0; i < 8; i++)
    {
        digitalWrite(_d[i], bitRead(value, i));
    }

    // Tempo de estabilização dos dados
    delayMicroseconds(2);

    // Pulso de escrita
    digitalWrite(_wr, LOW);

    delayMicroseconds(2);

    digitalWrite(_wr, HIGH);

    // Desativa o display
    digitalWrite(_cs, HIGH);

    // Intervalo mínimo validado experimentalmente.
    // Sem este atraso ocorre perda de caracteres.
    // Valor validado no hardware real: 1 ms.
    delay(1);
}


// ==========================================================
// Controle básico do display
// ==========================================================

void CU205SCPB::clear()
{
    sendByte(CU205_CLR);

    // Tempo para processamento do comando CLR
    delay(100);

    sendByte(CU205_CR);

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
    if(p >= CU205_COLUMNS)
    {
        p = CU205_COLUMNS - 1;
    }

    sendByte(CU205_ESC);
    sendByte('H');
    sendByte(p);

    _cursorPos = p;
}


void CU205SCPB::setBrightness(uint8_t value)
{
    sendByte(CU205_ESC);
    sendByte('L');
    sendByte(value);
}


// ==========================================================
// Controle do cursor
// ==========================================================

void CU205SCPB::cursorOff()
{
    sendByte(CU205_DC4);
}


void CU205SCPB::cursorOn()
{
    sendByte(CU205_DC5);
}


void CU205SCPB::backspace()
{
    sendByte(CU205_BS);

    if(_cursorPos > 0)
    {
        _cursorPos--;
    }
}


void CU205SCPB::tab()
{
    sendByte(CU205_HT);
}


void CU205SCPB::carriageReturn()
{
    sendByte(CU205_CR);

    _cursorPos = 0;
}


uint8_t CU205SCPB::getCursorPosition()
{
    return _cursorPos;
}


// ==========================================================
// Modos de operação
// ==========================================================

void CU205SCPB::autoReturnMode()
{
    sendByte(CU205_DC1);
}


void CU205SCPB::overwriteMode()
{
    sendByte(CU205_DC2);
}


void CU205SCPB::scrollMode()
{
    sendByte(CU205_DC3);
}


// ==========================================================
// Interface Print
// ==========================================================

size_t CU205SCPB::write(uint8_t c)
{
    // Ignora Line Feed
    if(c == CU205_LF)
    {
        return 1;
    }

    // Trata Carriage Return
    if(c == CU205_CR)
    {
        carriageReturn();
        return 1;
    }

    // Envia caractere ao display
    sendByte(c);

    // Atualiza posição interna do cursor
    if(_cursorPos < CU205_COLUMNS - 1)
    {
        _cursorPos++;
    }

    return 1;
}


// ==========================================================
// Funções de texto
// ==========================================================

void CU205SCPB::typeWriter(const char *text, uint16_t speed)
{
    while(*text)
    {
        write(*text);
        text++;

        delay(speed);
    }
}


void CU205SCPB::center(const char *text)
{
    uint8_t len = strlen(text);

    // Texto maior ou igual à largura do display
    if(len >= DISPLAY_WIDTH)
    {
        setCursor(0);
        print(text);
        return;
    }

    // Calcula posição central
    uint8_t position = (DISPLAY_WIDTH - len) / 2;

    setCursor(position);

    print(text);
}


void CU205SCPB::typeWriterCentered(const char *text,
                                    uint16_t speed)
{
    uint8_t len = strlen(text);

    // Texto maior ou igual à largura do display
    if(len >= DISPLAY_WIDTH)
    {
        setCursor(0);
    }
    else
    {
        uint8_t position = (DISPLAY_WIDTH - len) / 2;

        setCursor(position);
    }

    // Escreve caractere por caractere
    while(*text)
    {
        write(*text);
        text++;

        delay(speed);
    }
}


// ==========================================================
// Efeitos de texto
// ==========================================================

void CU205SCPB::blinkText(const char *text,
                          uint16_t interval,
                          uint8_t times)
{
    uint8_t len = strlen(text);

    // Salva posição inicial
    uint8_t startPos = _cursorPos;

    for(uint8_t i = 0; i < times; i++)
    {
        // Mostra o texto
        setCursor(startPos);

        print(text);

        delay(interval);

        // Apaga o texto
        setCursor(startPos);

        for(uint8_t j = 0; j < len; j++)
        {
            write(' ');
        }

        delay(interval);
    }

    // Retorna cursor à posição inicial
    setCursor(startPos);
}


// ==========================================================
// Rolagem de texto
// ==========================================================

void CU205SCPB::scrollText(const char *text,
                           uint16_t speed,
                           bool repeat,
                           uint16_t pause)
{
    do
    {
        const uint8_t width = DISPLAY_WIDTH;

        char buffer[256];

        uint16_t len = strlen(text);

        // Preenche buffer com espaços
        memset(buffer, ' ', sizeof(buffer));

        // Coloca texto após a área inicial
        memcpy(buffer + width, text, len);

        uint16_t total = len + width;

        // Utiliza modo overwrite
        overwriteMode();

        // Executa rolagem
        for(uint16_t pos = 0; pos <= total; pos++)
        {
            setCursor(0);

            for(uint8_t i = 0; i < width; i++)
            {
                write(buffer[pos + i]);
            }

            delay(speed);
        }

        // Pausa ao final da rolagem
        delay(pause);

    } while(repeat);
}


void CU205SCPB::marquee(const char *text,
                        uint16_t speed,
                        bool repeat,
                        uint16_t pause)
{
    do
    {
        // Executa uma rolagem completa
        scrollText(text, speed, false, 0);

        // Pausa entre ciclos
        delay(pause);

    } while(repeat);
}


// ==========================================================
// Barra de progresso
// ==========================================================

void CU205SCPB::progressBar(uint8_t percent)
{
    // Limita valor máximo
    if(percent > 100)
    {
        percent = 100;
    }

    // Calcula quantidade de caracteres preenchidos
    uint8_t filled = (DISPLAY_WIDTH * percent) / 100;

    // Inicia na primeira posição
    setCursor(0);

    // Desenha os 20 caracteres da barra
    for(uint8_t i = 0; i < DISPLAY_WIDTH; i++)
    {
        if(i < filled)
        {
            write('#');
        }
        else
        {
            write(' ');
        }
    }
}