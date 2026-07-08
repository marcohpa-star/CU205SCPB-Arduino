#ifndef CU205SCPB_H
#define CU205SCPB_H
#include <Arduino.h>
#include <Print.h>
#include "CU205SCPB_Commands.h"
class CU205SCPB: public Print{
public:
CU205SCPB(const uint8_t dataPins[8],uint8_t wr,uint8_t cs);
bool begin();
void clear(); void home(); void setCursor(uint8_t); void setBrightness(uint8_t);
size_t write(uint8_t) override; using Print::write;
private:
void sendByte(uint8_t);
uint8_t _d[8],_wr,_cs,_cursor=0;
};
#endif