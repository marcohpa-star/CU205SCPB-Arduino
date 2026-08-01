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
