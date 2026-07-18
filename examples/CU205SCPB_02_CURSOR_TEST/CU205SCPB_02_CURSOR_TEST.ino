#include <CU205SCPB.h>

uint8_t dataPins[8] = {2,3,4,5,6,7,8,9};

CU205SCPB vfd(dataPins,10,11);

void setup()
{
  Serial.begin(9600);

  vfd.begin();

  vfd.clear();

  // Posição 0
  vfd.setCursor(0);
  vfd.print("0");

  delay(1000);

  // Posição 5
  vfd.setCursor(5);
  vfd.print("5");

  delay(1000);

  // Posição 10
  vfd.setCursor(10);
  vfd.print("10");

  delay(1000);

  // Posição 19
  vfd.setCursor(19);
  vfd.print("X");

  Serial.print("Cursor final = ");
  Serial.println(vfd.getCursorPosition());
}

void loop()
{

}
