#include <CU205SCPB.h>

uint8_t dataPins[8] = {2,3,4,5,6,7,8,9};

CU205SCPB vfd(dataPins,10,11);

void setup()
{
  vfd.begin();

  vfd.clear();
  vfd.home();

  vfd.print("HELLO");

}

void loop()
{

}
