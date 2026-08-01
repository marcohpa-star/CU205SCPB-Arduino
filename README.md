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
