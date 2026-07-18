# CU205SCPB Arduino Library

Biblioteca Arduino para o display VFD Noritake CU205SCPB-T21A.

Driver desenvolvido para comunicação paralela de 8 bits utilizando o controlador Epson SED2000F.

---

## Características

- Interface paralela 8 bits
- Controle WR e CS
- Compatível com Arduino UNO e placas compatíveis
- Classe baseada em Arduino Print
- Escrita usando:
  - print()
  - println()

Recursos disponíveis:

- Limpeza do display
- Posicionamento do cursor
- Controle de brilho
- Controle do cursor
- Backspace
- Tab
- Modos DC1/DC2/DC3
- Scroll interno do controlador

---

## Hardware testado

Display:

Noritake CU205SCPB-T21A

Controlador:

Epson SED2000F

Interface utilizada:

Paralela 8 bits

---

## Ligações

Display → Arduino UNO

| Display | Arduino |
|---|---|
| D0 | 2 |
| D1 | 3 |
| D2 | 4 |
| D3 | 5 |
| D4 | 6 |
| D5 | 7 |
| D6 | 8 |
| D7 | 9 |
| WR | 10 |
| CS | 11 |
| GND | GND |
| VCC | 5V |

---

## Exemplo básico

```cpp
#include <CU205SCPB.h>

uint8_t dataPins[8]={2,3,4,5,6,7,8,9};

CU205SCPB vfd(dataPins,10,11);

void setup()
{
  vfd.begin();

  vfd.clear();
  vfd.print("HELLO");
}

void loop()
{

}