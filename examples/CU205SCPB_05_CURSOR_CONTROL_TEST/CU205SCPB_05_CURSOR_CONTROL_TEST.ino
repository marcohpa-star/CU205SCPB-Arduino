#include <CU205SCPB.h>

uint8_t dataPins[8] = {2,3,4,5,6,7,8,9};

CU205SCPB vfd(dataPins,10,11);


void setup()
{
  Serial.begin(115200);

  vfd.begin();

  // Teste cursor ligado
  vfd.clear();
  vfd.cursorOn();

  vfd.print("CURSOR ON");

  delay(2000);


  // Teste cursor desligado
  vfd.clear();
  vfd.cursorOff();

  vfd.print("CURSOR OFF");

  delay(2000);


  // Teste overwrite
  vfd.clear();
  vfd.overwriteMode();

  vfd.setCursor(5);
  vfd.print("ABC");

  delay(1000);

  vfd.setCursor(5);
  vfd.print("XYZ");

  delay(2000);


  // Teste backspace
  vfd.clear();

  vfd.print("ABCDE");

  delay(1000);

  vfd.backspace();
  vfd.backspace();

  vfd.print("XY");


  Serial.print("Cursor final = ");
  Serial.println(vfd.getCursorPosition());
}


void loop()
{

}
