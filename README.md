# Biblioteca Arduino CU205SCPB

Biblioteca Arduino para controle do display fluorescente a vácuo (VFD) Noritake CU205SCPB-T21A.

Driver desenvolvido para comunicação paralela de 8 bits utilizando o controlador Epson SED2000F.

## Características

- Interface paralela de 8 bits
- Display de 20 colunas × 1 linha
- Compatível com Arduino UNO e placas compatíveis
- Controle de posição do cursor
- Controle de brilho
- Controle do cursor
- Limpeza do display
- Posicionamento do cursor
- Modos de operação
- Escrita de texto
- Texto centralizado
- Efeito de máquina de escrever
- Efeito de máquina de escrever centralizado
- Texto piscante
- Rolagem de texto
- Efeito Marquee
- Barra de progresso
- Controle interno da posição do cursor
## Hardware

### Display

Noritake CU205SCPB-T21A

### Interface

A biblioteca utiliza a interface paralela de 8 bits do display.

São utilizados:

- 8 linhas de dados: D0 a D7
- WR — Write
- CS — Chip Select

### Pinagem do display

O display utilizado no desenvolvimento possui o seguinte mapeamento de conexão:

| Pino do display | Função |
|---|---|
| 1 | D7 |
| 2 | D6 |
| 3 | D5 |
| 4 | D4 |
| 5 | D3 |
| 6 | D2 |
| 7 | D1 |
| 8 | D0 |
| 9 | WR |
| 10 | CS |
| 11 | SIN/TO |
| 12 | BUSY |
| 13 | GND |
| 14 | GND |
| 15 | VCC |
| 16 | VCC |
## Instalação

A biblioteca pode ser instalada através do Arduino IDE utilizando o arquivo ZIP disponível na seção de Releases deste repositório.

### Instalação pelo Arduino IDE

1. Baixe o arquivo ZIP da versão desejada na seção **Releases**.
2. Abra o Arduino IDE.
3. Acesse **Sketch → Incluir Biblioteca → Adicionar Biblioteca ZIP...**
4. Selecione o arquivo ZIP baixado.
5. A biblioteca será instalada automaticamente.

Após a instalação, a biblioteca estará disponível em:

**Sketch → Incluir Biblioteca**

### Instalação manual

Também é possível instalar a biblioteca manualmente copiando a pasta da biblioteca para o diretório `libraries` da instalação do Arduino IDE.

Após a instalação, reinicie o Arduino IDE se a biblioteca não aparecer imediatamente na lista de bibliotecas disponíveis.
## Primeiro exemplo

O exemplo abaixo inicializa o display e escreve o texto `HELLO WORLD` na primeira posição do display.

```cpp
#include <CU205SCPB.h>

const uint8_t dataPins[8] = {
    2, 3, 4, 5, 6, 7, 8, 9
};

const uint8_t WR_PIN = 10;
const uint8_t CS_PIN = 11;

CU205SCPB vfd(dataPins, WR_PIN, CS_PIN);

void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.setCursor(0);

    vfd.print("HELLO WORLD");
}

void loop()
{
}
> **Nota:** Os números dos pinos utilizados no exemplo são apenas uma configuração de exemplo. Os pinos podem ser alterados conforme a montagem utilizada, desde que os oito pinos de dados, WR e CS sejam definidos corretamente no construtor da biblioteca.



## Funções disponíveis

A biblioteca `CU205SCPB` disponibiliza funções para inicialização, controle do display, gerenciamento do cursor, modos de operação, efeitos de texto, rolagem e barra de progresso.

---

### Informações do display

A biblioteca possui constantes que informam as dimensões do display:

```cpp
CU205SCPB::DISPLAY_WIDTH
```

Retorna a largura do display em caracteres.

Para o CU205SCPB-T21A:

```cpp
20
```

Exemplo:

```cpp
uint8_t largura = CU205SCPB::DISPLAY_WIDTH;
```

---

```cpp
CU205SCPB::DISPLAY_HEIGHT
```

Retorna a quantidade de linhas do display.

Para o CU205SCPB-T21A:

```cpp
1
```

Exemplo:

```cpp
uint8_t altura = CU205SCPB::DISPLAY_HEIGHT;
```

---

### `begin()`

Inicializa a comunicação entre o Arduino e o display VFD.

Uso:

```cpp
vfd.begin();
```

Deve ser chamada no `setup()` antes de utilizar as demais funções da biblioteca.

Exemplo:

```cpp
void setup()
{
    vfd.begin();
}
```

---

### `clear()`

Limpa o conteúdo do display.

Uso:

```cpp
vfd.clear();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.print("HELLO");
}
```

---

### `home()`

Retorna o cursor para a posição inicial do display.

Uso:

```cpp
vfd.home();
```

Exemplo:

```cpp
vfd.setCursor(10);

vfd.print("TESTE");

vfd.home();

vfd.print("INICIO");
```

---

### `setCursor(uint8_t pos)`

Posiciona o cursor em uma posição específica do display.

O display possui 20 posições, numeradas de `0` a `19`.

Parâmetro:

* `pos` — posição do cursor.

Exemplo:

```cpp
vfd.setCursor(0);
vfd.print("INICIO");
```

Para escrever na última posição:

```cpp
vfd.setCursor(19);
vfd.print("X");
```

---

### `setBrightness(uint8_t value)`

Define o nível de brilho do display.

Parâmetro:

* `value` — valor de brilho utilizado pela biblioteca.

Exemplo:

```cpp
vfd.setBrightness(5);
```

O valor disponível depende da faixa de brilho implementada pela biblioteca e pelo controlador do display.

---

### `print()`

A biblioteca é derivada da classe `Print` do Arduino. Isso permite utilizar a função `print()` para enviar textos e outros dados compatíveis com a interface `Print`.

Exemplo:

```cpp
vfd.print("HELLO WORLD");
```

Também é possível utilizar valores numéricos:

```cpp
vfd.print(123);
```

E textos combinados:

```cpp
vfd.print("TEMP: ");
vfd.print(25);
vfd.print(" C");
```

---

### `write()`

A função `write()` envia um caractere individual para o display.

Ela é utilizada internamente pela interface `Print` e permite que funções como `print()` funcionem normalmente.

Exemplo:

```cpp
vfd.write('A');
```

Também pode ser utilizada para enviar caracteres individualmente:

```cpp
vfd.write('H');
vfd.write('E');
vfd.write('L');
vfd.write('L');
vfd.write('O');
```

---

### Versão da biblioteca

A versão atual da biblioteca pode ser identificada através da constante:

```cpp
CU205SCPB_VERSION
```

Na versão atual:

```cpp
1.3.2
```

Exemplo:

```cpp
Serial.println(CU205SCPB_VERSION);
```
### Controle do cursor

A biblioteca permite controlar a exibição do cursor, movimentá-lo e consultar sua posição atual.

---

### `cursorOn()`

Ativa a exibição do cursor no display.

Uso:

```cpp
vfd.cursorOn();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.cursorOn();

    vfd.print("CURSOR ATIVO");
}
```

---

### `cursorOff()`

Desativa a exibição do cursor no display.

Uso:

```cpp
vfd.cursorOff();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.print("CURSOR DESATIVADO");

    vfd.cursorOff();
}
```

---

### `backspace()`

Move o cursor uma posição para trás.

Uso:

```cpp
vfd.backspace();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.setCursor(5);

    vfd.print("ABC");

    vfd.backspace();

    vfd.print("X");
}
```

Neste exemplo, o caractere `X` será escrito na posição anterior à posição atual do cursor.

---

### `tab()`

Avança o cursor para a próxima posição de tabulação.

Uso:

```cpp
vfd.tab();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.print("A");

    vfd.tab();

    vfd.print("B");
}
```

A movimentação exata depende do comportamento de tabulação implementado pelo controlador do display.

---

### `carriageReturn()`

Retorna o cursor para o início da linha atual.

Como o CU205SCPB-T21A possui uma única linha de 20 caracteres, o cursor retorna para a posição inicial.

Uso:

```cpp
vfd.carriageReturn();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.setCursor(10);

    vfd.print("TESTE");

    vfd.carriageReturn();

    vfd.print("INICIO");
}
```

---

### `getCursorPosition()`

Retorna a posição atual do cursor mantida internamente pela biblioteca.

Uso:

```cpp
uint8_t pos = vfd.getCursorPosition();
```

Exemplo:

```cpp
void setup()
{
    Serial.begin(9600);

    vfd.begin();

    vfd.clear();

    vfd.setCursor(5);

    Serial.print("Posicao atual: ");
    Serial.println(vfd.getCursorPosition());
}
```

O valor retornado representa a posição atual do cursor, considerando a numeração das posições do display de `0` a `19`.

---

### Exemplo completo de controle do cursor

```cpp
#include <CU205SCPB.h>

const uint8_t dataPins[8] = {
    2, 3, 4, 5, 6, 7, 8, 9
};

const uint8_t WR_PIN = 10;
const uint8_t CS_PIN = 11;

CU205SCPB vfd(dataPins, WR_PIN, CS_PIN);

void setup()
{
    Serial.begin(9600);

    vfd.begin();

    vfd.clear();

    vfd.setCursor(5);

    vfd.print("HELLO");

    Serial.print("Cursor: ");
    Serial.println(vfd.getCursorPosition());

    vfd.cursorOn();
}

void loop()
{
}
```

Neste exemplo, o display é inicializado, o cursor é posicionado na posição `5`, o texto é escrito e a posição atual do cursor é enviada ao Monitor Serial.
