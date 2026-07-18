#include <CU205SCPB.h>
const uint8_t p[8]={2,3,4,5,6,7,8,9};
CU205SCPB vfd(p,10,11);
void setup(){vfd.begin();vfd.clear();vfd.setBrightness(255);vfd.setCursor(0);vfd.print("HELLO");}
void loop(){}
