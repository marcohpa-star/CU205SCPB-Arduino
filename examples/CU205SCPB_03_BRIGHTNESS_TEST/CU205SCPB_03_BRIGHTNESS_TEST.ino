#include <CU205SCPB.h>

uint8_t dataPins[8] = {2,3,4,5,6,7,8,9};

CU205SCPB vfd(dataPins,10,11);

void setup()
{
  vfd.begin();

  vfd.clear();
  vfd.print("BRIGHTNESS");

  delay(2000);

  vfd.clear();
  vfd.print("LEVEL 1");
  vfd.setBrightness(1);

  delay(2000);

  vfd.clear();
  vfd.print("LEVEL 5");
  vfd.setBrightness(5);

  delay(2000);

  vfd.clear();
  vfd.print("LEVEL 10");
  vfd.setBrightness(10);
}

void loop()
{

}
