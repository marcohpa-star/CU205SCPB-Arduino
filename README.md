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
## Modos de operação

A biblioteca disponibiliza três modos de operação para controlar o comportamento da escrita de texto no display.

---

### `autoReturnMode()`

Ativa o modo de retorno automático.

Neste modo, quando a escrita atinge o final da linha, o controlador do display retorna ao início da linha de acordo com o comportamento definido pelo display.

Uso:

```cpp
vfd.autoReturnMode();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.autoReturnMode();

    vfd.print("HELLO WORLD");
}
```

---

### `overwriteMode()`

Ativa o modo de sobrescrita.

Neste modo, novos caracteres escritos sobre uma posição já ocupada substituem o conteúdo existente naquela posição.

Uso:

```cpp
vfd.overwriteMode();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.overwriteMode();

    vfd.setCursor(0);

    vfd.print("HELLO");

    vfd.setCursor(0);

    vfd.print("ABCDE");
}
```

Após a segunda escrita, os caracteres `ABCDE` substituem os caracteres que estavam anteriormente nas primeiras posições.

---

### `scrollMode()`

Ativa o modo de rolagem horizontal do display.

Neste modo, quando novos caracteres ultrapassam a área disponível do display, o conteúdo pode ser deslocado horizontalmente de acordo com o comportamento do controlador.

Uso:

```cpp
vfd.scrollMode();
```

Exemplo:

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.scrollMode();

    vfd.print("TEXTO MUITO LONGO PARA O DISPLAY");
}
```

---

### Exemplo de seleção de modo

Os modos de operação podem ser selecionados conforme a necessidade da aplicação.

```cpp
void setup()
{
    vfd.begin();

    vfd.clear();

    // Seleciona o modo de retorno automático
    vfd.autoReturnMode();

    vfd.print("TESTE");
}
```

Para utilizar o modo de sobrescrita:

```cpp
vfd.overwriteMode();
```

Para utilizar o modo de rolagem:

```cpp
vfd.scrollMode();
```

A escolha do modo deve ser feita antes da escrita do texto que dependerá desse comportamento.

> **Nota:** Os modos de operação controlam o comportamento interno do display. Eles são diferentes das funções de efeitos e rolagem implementadas pela biblioteca, como `scrollText()` e `marquee()`.
## Efeitos e funções de texto

A biblioteca disponibiliza funções para criar efeitos de escrita, centralizar textos e produzir efeitos de pisca-pisca.

---

### `typeWriter(const char *text, uint16_t speed)`

Escreve um texto no display caractere por caractere, criando um efeito semelhante ao de uma máquina de escrever.

Parâmetros:

* `text` — texto que será exibido.
* `speed` — intervalo entre a escrita de cada caractere, em milissegundos.

Uso:

```cpp id="x5n3p2"
vfd.typeWriter("HELLO WORLD", 100);
```

Neste exemplo, cada caractere será escrito com um intervalo de aproximadamente `100 ms`.

Exemplo:

```cpp id="r7g1ab"
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.typeWriter("HELLO WORLD", 100);
}
```

Um valor menor de `speed` produz uma escrita mais rápida.

Um valor maior produz uma escrita mais lenta.

---

### `typeWriterCentered(const char *text, uint16_t speed)`

Escreve o texto caractere por caractere utilizando um efeito de máquina de escrever e posiciona o texto de forma centralizada no display.

Parâmetros:

* `text` — texto que será exibido.
* `speed` — intervalo entre a escrita de cada caractere, em milissegundos.

Uso:

```cpp id="x8p2kc"
vfd.typeWriterCentered("HELLO WORLD", 100);
```

Exemplo:

```cpp id="z1m4qr"
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.typeWriterCentered("HELLO WORLD", 100);
}
```

Esta função é útil para mensagens de apresentação, telas de inicialização e interfaces que precisam apresentar uma mensagem centralizada com efeito de escrita progressiva.

---

### `center(const char *text)`

Centraliza um texto na linha do display.

Parâmetro:

* `text` — texto que será exibido.

Uso:

```cpp id="q9s5lm"
vfd.center("HELLO WORLD");
```

Exemplo:

```cpp id="k4v7ps"
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.center("HELLO WORLD");
}
```

Como o display possui 20 posições, a função calcula automaticamente a posição inicial necessária para centralizar o texto.

Essa função é especialmente útil para títulos e mensagens de status.

---

### `blinkText(const char *text, uint16_t interval, uint8_t times)`

Exibe um texto com efeito de pisca-pisca.

Parâmetros:

* `text` — texto que será exibido.
* `interval` — intervalo entre os estados ligado e desligado, em milissegundos.
* `times` — quantidade de vezes que o texto irá piscar.

Uso:

```cpp id="v3k6pd"
vfd.blinkText("WARNING", 500, 3);
```

Neste exemplo, o texto `WARNING` pisca com um intervalo de `500 ms`, durante `3` ciclos.

Exemplo:

```cpp id="w8n2fz"
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.blinkText("WARNING", 500, 3);
}
```

---

### Exemplo combinado

As funções de texto podem ser utilizadas em diferentes etapas de uma interface.

Exemplo:

```cpp id="n6r1vs"
void setup()
{
    vfd.begin();

    vfd.clear();

    // Exibe uma mensagem centralizada
    vfd.center("CU205SCPB");

    delay(2000);

    // Limpa o display
    vfd.clear();

    // Escreve caractere por caractere
    vfd.typeWriterCentered("HELLO WORLD", 100);

    delay(2000);

    // Exibe uma mensagem piscando
    vfd.clear();

    vfd.blinkText("READY", 500, 3);
}

void loop()
{
}
```

Esse exemplo demonstra como combinar diferentes funções da biblioteca para criar uma sequência simples de apresentação no display.
## Rolagem de texto

A biblioteca possui funções para apresentar textos maiores que a largura disponível do display através de rolagem horizontal.

O display CU205SCPB-T21A possui 20 posições de caracteres. Quando um texto ultrapassa essa largura, as funções de rolagem permitem apresentar todo o conteúdo de forma progressiva.

---

### `scrollText(const char *text, uint16_t speed, bool repeat, uint16_t pause)`

Exibe um texto utilizando rolagem horizontal.

A função permite controlar a velocidade da rolagem, definir se o texto deve ser repetido e configurar uma pausa entre as repetições.

Parâmetros:

* `text` — texto que será exibido.
* `speed` — intervalo entre os movimentos da rolagem, em milissegundos.
* `repeat` — define se a rolagem será repetida.
* `pause` — tempo de pausa entre as repetições, em milissegundos.

Os parâmetros `speed`, `repeat` e `pause` possuem valores padrão:

```cpp
speed = 250
repeat = false
pause = 1000
```

Isso permite utilizar a função de maneira simplificada.

Exemplo:

```cpp id="z7q2mh"
vfd.scrollText("ESTE E UM TEXTO LONGO PARA O DISPLAY");
```

Neste caso, serão utilizados os valores padrão da função.

---

### Definindo a velocidade

A velocidade da rolagem pode ser alterada através do parâmetro `speed`.

Exemplo:

```cpp id="j3r8vn"
vfd.scrollText("TEXTO DESLIZANDO PELO DISPLAY", 100);
```

Um valor menor produz uma rolagem mais rápida.

Um valor maior produz uma rolagem mais lenta.

---

### Rolagem sem repetição

Para executar a rolagem uma única vez, utilize:

```cpp id="m5k9wx"
vfd.scrollText(
    "MENSAGEM DE TESTE",
    250,
    false,
    1000
);
```

Neste exemplo, o texto é apresentado uma vez e a função termina após concluir a rolagem.

---

### Rolagem com repetição

Para repetir continuamente a rolagem, utilize:

```cpp id="p2v6cs"
vfd.scrollText(
    "MENSAGEM REPETITIVA",
    250,
    true,
    1000
);
```

O parâmetro `true` ativa a repetição.

O parâmetro `pause` define o intervalo de espera entre uma repetição e outra.

---

### Exemplo completo

```cpp id="a8d4qy"
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

    vfd.scrollText(
        "BEM VINDO AO DISPLAY CU205SCPB",
        150,
        false,
        1000
    );
}

void loop()
{
}
```

---

### `marquee(const char *text, uint16_t speed, bool repeat, uint16_t pause)`

Executa um efeito de letreiro (marquee) com o texto informado.

Parâmetros:

* `text` — texto que será exibido.
* `speed` — intervalo entre os movimentos do texto, em milissegundos.
* `repeat` — define se o efeito será repetido.
* `pause` — tempo de pausa entre as repetições, em milissegundos.

Uso:

```cpp id="n4x8vt"
vfd.marquee(
    "CU205SCPB VFD DISPLAY",
    150,
    false,
    1000
);
```

Para repetir continuamente:

```cpp id="h7c2kp"
vfd.marquee(
    "CU205SCPB VFD DISPLAY",
    150,
    true,
    1000
);
```

---

### Diferença entre `scrollText()` e `marquee()`

As duas funções são destinadas à apresentação de textos em movimento.

A função:

```cpp id="b6m1zs"
scrollText()
```

é utilizada para realizar a rolagem de um texto pelo display.

A função:

```cpp id="c9q4ld"
marquee()
```

é destinada a criar um efeito de letreiro.

Ambas permitem configurar:

* velocidade;
* repetição;
* pausa entre repetições.

A implementação dessas funções pode ser utilizada para criar mensagens de status, avisos, títulos e informações maiores que os 20 caracteres disponíveis no display.
## Barra de progresso

A biblioteca disponibiliza uma função para apresentar visualmente o progresso de uma operação utilizando a largura disponível do display.

---

### `progressBar(uint8_t percent)`

Exibe uma barra de progresso correspondente ao percentual informado.

Parâmetro:

* `percent` — percentual de progresso, de `0` a `100`.

Uso:

```cpp id="p3k7vx"
vfd.progressBar(50);
```

Neste exemplo, a barra representa aproximadamente 50% do progresso.

---

### Exemplo básico

```cpp id="h8m2qz"
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

    vfd.progressBar(50);
}

void loop()
{
}
```

---

### Atualizando o progresso

A função pode ser chamada várias vezes para atualizar o percentual apresentado.

Exemplo:

```cpp id="s6v1nd"
void loop()
{
    for (uint8_t percent = 0; percent <= 100; percent++)
    {
        vfd.progressBar(percent);

        delay(100);
    }
}
```

Neste exemplo, o progresso é atualizado gradualmente de `0%` até `100%`.

---

### Exemplo com etapas

A barra também pode ser utilizada para representar diferentes etapas de uma operação.

```cpp id="k9x4br"
void setup()
{
    vfd.begin();

    vfd.clear();

    vfd.progressBar(0);

    delay(1000);

    vfd.progressBar(25);

    delay(1000);

    vfd.progressBar(50);

    delay(1000);

    vfd.progressBar(75);

    delay(1000);

    vfd.progressBar(100);
}

void loop()
{
}
```

Esse tipo de utilização pode ser aplicado em processos como inicialização de equipamentos, carregamento de dados, execução de tarefas ou qualquer operação que possa ser representada por um percentual.

---

### Faixa de valores

A função utiliza um valor percentual entre:

```cpp id="e5r2kw"
0
```

e:

```cpp id="u7m3qc"
100
```

Onde:

* `0` representa o início do progresso;
* `50` representa aproximadamente metade do progresso;
* `100` representa o progresso completo.

Exemplo:

```cpp id="v2n8fy"
vfd.progressBar(0);    // 0%
vfd.progressBar(25);   // 25%
vfd.progressBar(50);   // 50%
vfd.progressBar(75);   // 75%
vfd.progressBar(100);  // 100%
```

> **Nota:** A aparência visual da barra de progresso depende da implementação utilizada pela biblioteca e dos caracteres disponíveis no display VFD.
## Conexão do hardware

A biblioteca `CU205SCPB` utiliza a interface paralela de 8 bits do display Noritake CU205SCPB-T21A.

O display também possui outros sinais disponíveis, porém a biblioteca utiliza os seguintes sinais para comunicação:

* 8 linhas de dados (`D0` a `D7`)
* `WR` — Write
* `CS` — Chip Select

A linha `BUSY` não é necessária para a configuração básica da comunicação utilizada pela biblioteca.

---

### Pinagem do conector

A tabela abaixo apresenta a pinagem utilizada no display CU205SCPB-T21A:

| Pino do display | Sinal  | Função                              |
| --------------- | ------ | ----------------------------------- |
| 1               | D7     | Dados bit 7                         |
| 2               | D6     | Dados bit 6                         |
| 3               | D5     | Dados bit 5                         |
| 4               | D4     | Dados bit 4                         |
| 5               | D3     | Dados bit 3                         |
| 6               | D2     | Dados bit 2                         |
| 7               | D1     | Dados bit 1                         |
| 8               | D0     | Dados bit 0                         |
| 9               | WR     | Write                               |
| 10              | CS     | Chip Select                         |
| 11              | SIN/TO | Entrada serial / função alternativa |
| 12              | BUSY   | Sinal de ocupado                    |
| 13              | GND    | Terra                               |
| 14              | GND    | Terra                               |
| 15              | VCC    | Alimentação                         |
| 16              | VCC    | Alimentação                         |

---

### Interface paralela de 8 bits

Para utilizar a biblioteca através da interface paralela, conecte as oito linhas de dados do Arduino às entradas correspondentes do display.

A ordem dos pinos é:

```text
Display       Arduino
-------------------------
D0     -----> DATA[0]
D1     -----> DATA[1]
D2     -----> DATA[2]
D3     -----> DATA[3]
D4     -----> DATA[4]
D5     -----> DATA[5]
D6     -----> DATA[6]
D7     -----> DATA[7]

WR     -----> WR_PIN
CS     -----> CS_PIN
```

Os pinos utilizados no Arduino podem ser escolhidos livremente, desde que sejam definidos corretamente no construtor da biblioteca.

---

### Exemplo de configuração

No exemplo abaixo, os pinos digitais `2` a `9` são utilizados para os dados:

```cpp
const uint8_t dataPins[8] = {
    2, 3, 4, 5, 6, 7, 8, 9
};

const uint8_t WR_PIN = 10;
const uint8_t CS_PIN = 11;

CU205SCPB vfd(dataPins, WR_PIN, CS_PIN);
```

A correspondência é:

| Sinal do display | Pino Arduino |
| ---------------- | ------------ |
| D0               | 2            |
| D1               | 3            |
| D2               | 4            |
| D3               | 5            |
| D4               | 6            |
| D5               | 7            |
| D6               | 8            |
| D7               | 9            |
| WR               | 10           |
| CS               | 11           |

> **Importante:** A sequência do vetor `dataPins[]` deve corresponder à ordem `D0` até `D7`. Portanto, o primeiro elemento do vetor representa `D0` e o último representa `D7`.

---

### Alimentação

As conexões de alimentação devem ser realizadas de acordo com as especificações elétricas do módulo e do fabricante.

Conecte:

```text
Display
----------------
Pino 13  -> GND
Pino 14  -> GND

Pino 15  -> VCC
Pino 16  -> VCC
```

> **⚠️ Atenção:** Verifique a tensão de alimentação especificada para o seu módulo CU205SCPB-T21A antes de realizar a conexão. Não conecte a alimentação apenas com base na numeração dos pinos. Consulte a documentação técnica do display utilizado.

---

### Sobre o sinal BUSY

O display possui um sinal `BUSY` no pino 12.

A versão atual da biblioteca utiliza uma comunicação baseada no envio dos comandos através das linhas de dados e dos sinais `WR` e `CS`, sem exigir a leitura do sinal `BUSY` para o funcionamento básico.

Por esse motivo, o `BUSY` não precisa ser conectado para utilizar os exemplos básicos da biblioteca.

---

### Sobre o pino SIN/TO

O pino 11 possui a identificação `SIN/TO` e está relacionado à interface serial ou a funções alternativas do display.

A comunicação utilizada pela biblioteca nesta versão é a interface paralela de 8 bits. Portanto, esse pino não é utilizado nos exemplos de comunicação paralela apresentados neste projeto.

---

### Resumo da conexão

Para utilizar a biblioteca no modo paralelo de 8 bits, são necessários:

* 8 pinos digitais para `D0` a `D7`;
* 1 pino digital para `WR`;
* 1 pino digital para `CS`;
* GND;
* VCC.

Total de sinais digitais utilizados:

```text
8 pinos de dados
+ 1 WR
+ 1 CS
------------
10 pinos digitais
```

A configuração dos pinos pode ser alterada no programa conforme a necessidade do projeto.
## Compatibilidade e requisitos

A biblioteca `CU205SCPB` foi desenvolvida para facilitar a utilização do display VFD Noritake CU205SCPB-T21A através de microcontroladores compatíveis com a plataforma Arduino.

---

### Hardware testado

A biblioteca foi desenvolvida e validada utilizando:

* Display VFD Noritake CU205SCPB-T21A
* Arduino UNO
* Interface paralela de 8 bits

O funcionamento foi validado em hardware real durante o desenvolvimento da biblioteca.

---

### Interface de comunicação

A versão atual utiliza:

* Interface paralela de 8 bits
* 8 linhas de dados: `D0` a `D7`
* Sinal `WR`
* Sinal `CS`

A biblioteca permite definir livremente os pinos utilizados pelo Arduino através do construtor:

```cpp
CU205SCPB(
    const uint8_t p[8],
    uint8_t wr,
    uint8_t cs
);
```

---

### Plataforma Arduino

A biblioteca foi desenvolvida utilizando a linguagem C++ e as APIs padrão da plataforma Arduino.

A classe principal herda da classe `Print`:

```cpp
class CU205SCPB : public Print
```

Isso permite utilizar funções compatíveis com a interface `Print`, como:

```cpp
vfd.print("HELLO WORLD");
```

e:

```cpp
vfd.write('A');
```

---

### Requisitos

Para utilizar a biblioteca são necessários:

* Uma placa compatível com Arduino;
* Um display Noritake CU205SCPB-T21A compatível com a interface paralela utilizada;
* 8 pinos digitais para as linhas de dados;
* 1 pino digital para `WR`;
* 1 pino digital para `CS`;
* Alimentação adequada para o display;
* Arduino IDE ou ambiente de desenvolvimento compatível com bibliotecas Arduino.

---

### Bibliotecas externas

A biblioteca `CU205SCPB` utiliza apenas recursos padrão da plataforma Arduino.

Não são necessárias bibliotecas externas adicionais para utilizar as funções básicas da biblioteca.

A biblioteca utiliza:

```cpp
#include <Arduino.h>
```

e:

```cpp
#include <Print.h>
```

Esses arquivos fazem parte da plataforma Arduino.

---

### Compatibilidade com outras placas

A biblioteca foi desenvolvida e testada inicialmente com Arduino UNO.

Como a comunicação utiliza funções padrão da plataforma Arduino e permite configurar os pinos através do construtor, outras placas compatíveis podem ser utilizadas, desde que:

* possuam pinos digitais suficientes;
* operem em níveis elétricos compatíveis com o display;
* sejam compatíveis com a API Arduino utilizada pela biblioteca.

O funcionamento em outras plataformas não testadas deve ser validado pelo usuário antes da utilização em projetos definitivos.

---

### Versão atual

Versão atual da biblioteca:

```text
1.3.2
```

Esta versão representa o estado atual do desenvolvimento da biblioteca no momento da publicação deste documento.
## Estrutura do projeto

A biblioteca está organizada de acordo com a estrutura padrão utilizada por bibliotecas Arduino.

A estrutura atual do projeto é:

```text
CU205SCPB-Arduino/
│
├── examples/
│   └── ...
│
├── src/
│   ├── CU205SCPB.cpp
│   ├── CU205SCPB.h
│   └── CU205SCPB_Commands.h
│
├── library.properties
├── LICENSE
└── README.md
```

---

### `src/`

A pasta `src` contém os arquivos principais da biblioteca.

---

### `src/CU205SCPB.h`

Arquivo de cabeçalho principal da biblioteca.

Contém:

* definição da classe `CU205SCPB`;
* declaração das funções públicas;
* constantes de configuração;
* definição dos pinos internos;
* controle do estado interno da biblioteca.

A classe principal é:

```cpp
class CU205SCPB : public Print
```

---

### `src/CU205SCPB.cpp`

Contém a implementação das funções declaradas no arquivo `CU205SCPB.h`.

É neste arquivo que estão implementadas as funções responsáveis por:

* inicialização do display;
* envio de dados;
* controle do cursor;
* controle de brilho;
* modos de operação;
* efeitos de texto;
* rolagem;
* barra de progresso.

---

### `src/CU205SCPB_Commands.h`

Contém as definições relacionadas aos comandos utilizados pela biblioteca para comunicação com o controlador do display.

A separação dos comandos em um arquivo próprio facilita a manutenção e a evolução futura do projeto.

---

### `examples/`

A pasta `examples` contém exemplos de utilização da biblioteca.

Os exemplos permitem testar individualmente as principais funções do display e servem como referência para o desenvolvimento de novos projetos.

Exemplos podem incluir funcionalidades como:

* inicialização;
* escrita de texto;
* controle do cursor;
* brilho;
* rolagem;
* efeitos de texto;
* barra de progresso.

Os exemplos podem ser acessados diretamente pelo Arduino IDE através do menu:

```text
Arquivo
→ Exemplos
→ CU205SCPB
```

---

### `library.properties`

Arquivo utilizado pelo Arduino IDE para identificar e gerenciar as informações da biblioteca.

Esse arquivo contém informações como:

* nome da biblioteca;
* versão;
* autor;
* descrição;
* categoria;
* URL do projeto;
* requisitos da biblioteca.

A versão atual da biblioteca é:

```text
1.3.2
```

---

### `README.md`

É o arquivo principal de documentação do projeto.

Ele apresenta informações sobre:

* descrição da biblioteca;
* instalação;
* primeiro exemplo;
* funções disponíveis;
* conexão do hardware;
* compatibilidade;
* estrutura do projeto;
* informações de utilização.

---

### `LICENSE`

Define os termos legais de utilização, modificação e distribuição do código da biblioteca.

Os usuários devem consultar este arquivo para conhecer as condições de uso do projeto.

---

### Organização da biblioteca

A separação entre código-fonte, exemplos e documentação facilita a manutenção do projeto.

De forma simplificada:

```text
src/
    Código da biblioteca

examples/
    Exemplos de utilização

library.properties
    Informações da biblioteca

README.md
    Documentação

LICENSE
    Termos de licença
```

Essa estrutura segue o modelo utilizado por bibliotecas Arduino e facilita a instalação e utilização do projeto.
