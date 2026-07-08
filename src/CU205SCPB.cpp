#include "CU205SCPB.h"
#include <string.h>
CU205SCPB::CU205SCPB(const uint8_t p[8],uint8_t wr,uint8_t cs){memcpy(_d,p,8);_wr=wr;_cs=cs;}
bool CU205SCPB::begin(){for(int i=0;i<8;i++){pinMode(_d[i],OUTPUT);digitalWrite(_d[i],LOW);} pinMode(_wr,OUTPUT); pinMode(_cs,OUTPUT); digitalWrite(_wr,HIGH); digitalWrite(_cs,HIGH); delay(100); clear(); home(); return true;}
void CU205SCPB::sendByte(uint8_t v){digitalWrite(_cs,LOW); for(int i=0;i<8;i++) digitalWrite(_d[i],(v>>i)&1); delayMicroseconds(10); digitalWrite(_wr,LOW); delayMicroseconds(10); digitalWrite(_wr,HIGH); digitalWrite(_cs,HIGH);}
void CU205SCPB::clear(){sendByte(CU205_CMD_CLEAR);_cursor=0;}
void CU205SCPB::home(){sendByte(CU205_CMD_HOME);_cursor=0;}
void CU205SCPB::setCursor(uint8_t p){if(p>19)p=19; sendByte(CU205_CMD_ESC); sendByte(CU205_CMD_CURSOR); sendByte(p); _cursor=p;}
void CU205SCPB::setBrightness(uint8_t v){sendByte(CU205_CMD_ESC); sendByte(CU205_CMD_BRIGHTNESS); sendByte(v);}
size_t CU205SCPB::write(uint8_t c){sendByte(c); if(_cursor<19)_cursor++; return 1;}
