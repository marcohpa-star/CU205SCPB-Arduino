#include <CU205SCPB.h>

uint8_t dataPins[8] = {2,3,4,5,6,7,8,9};

CU205SCPB vfd(dataPins,10,11);


void setup()
{
  Serial.begin(9600);

  vfd.begin();


  // TESTE 1 - Inicialização
  vfd.clear();
  vfd.print("CU205 TEST");
  delay(2000);


  // TESTE 2 - Posições
  vfd.clear();

  vfd.setCursor(0);
  vfd.print("0");

  vfd.setCursor(5);
  vfd.print("5");

  vfd.setCursor(10);
  vfd.print("10");

  vfd.setCursor(19);
  vfd.print("X");

  delay(3000);


  // TESTE 3 - Brilho
  vfd.clear();
  vfd.print("BRIGHT");
  
  vfd.setBrightness(2);
  delay(1000);

  vfd.setBrightness(8);
  delay(1000);

  vfd.setBrightness(15);
  delay(2000);


  // TESTE 4 - Cursor
  vfd.clear();
  vfd.cursorOn();
  vfd.print("CURSOR");

  delay(2000);

  vfd.cursorOff();


  // Final
  vfd.clear();
  vfd.print("TEST OK");

  Serial.println("CU205SCPB FACTORY TEST OK");
}


void loop()
{

}
