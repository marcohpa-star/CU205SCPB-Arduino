#ifndef CU205SCPB_H
#define CU205SCPB_H
#include <Arduino.h>
#include <Print.h>
#define CU205SCPB_VERSION "1.1.0"
class CU205SCPB: public Print{
public:
CU205SCPB(const uint8_t p[8],uint8_t wr,uint8_t cs);
bool begin();
void clear();
void home();
void setCursor(uint8_t pos);
void setBrightness(uint8_t value);

void cursorOn();
void cursorOff();

void backspace();
void tab();
void carriageReturn();

void autoReturnMode();
void overwriteMode();
void scrollMode(); uint8_t getCursorPosition();

size_t write(uint8_t c) override;
private:

    uint8_t _d[8];
    uint8_t _wr;
    uint8_t _cs;

    // Posição atual do cursor (mantida pela biblioteca)
    uint8_t _cursorPos;
   
void sendByte(uint8_t);
};
#endif
