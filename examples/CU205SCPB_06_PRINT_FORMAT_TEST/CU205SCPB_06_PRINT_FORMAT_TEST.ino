#include <CU205SCPB.h>

uint8_t dataPins[8] = {2,3,4,5,6,7,8,9};

CU205SCPB vfd(dataPins,10,11);


void setup()
{
  Serial.begin(9600);

  vfd.begin();

  vfd.clear();

  vfd.print("TEMP: ");
  vfd.print(25);
  vfd.print("C");

  delay(3000);


  vfd.clear();

  vfd.print("VALUE: ");
  vfd.print(255, HEX);

  delay(3000);


  vfd.clear();

  vfd.println("LINE1");
  vfd.println("LINE2");

  Serial.print("Cursor = ");
  Serial.println(vfd.getCursorPosition());
}


void loop()
{

}
