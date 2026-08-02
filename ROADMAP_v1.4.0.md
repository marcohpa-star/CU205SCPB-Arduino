# CU205SCPB Arduino Library

# Roadmap da Versão 1.4.0

A versão 1.4.0 tem como objetivo transformar a biblioteca CU205SCPB em uma biblioteca voltada para construção de interfaces de usuário (UI), mantendo total compatibilidade com a versão 1.3.2.

## Objetivos

- Manter compatibilidade com todos os programas existentes.
- Facilitar a criação de interfaces para displays de 20 caracteres.
- Reduzir a quantidade de código necessária nas aplicações.
- Preparar a biblioteca para o projeto Smart Clock.

---

# Filosofia da versão 1.4.0

A biblioteca deixa de ser apenas uma interface de comunicação com o display e passa a oferecer recursos para construção de interfaces gráficas baseadas em texto.

---

# Planejamento

## Fase 1

### Funções auxiliares

- [x] printAt()

- [ ] clearToEnd()

- [ ] fill()

- [ ] fillRange()

---

## Fase 2

### Áreas de trabalho (Work Areas)

Novidade da versão 1.4.0.

Permite dividir o display em regiões independentes.

Exemplo:

Hora

Informações

Menus

Status

Funções previstas:

- [ ] setArea()

- [ ] clearArea()

- [ ] printArea()

- [ ] scrollArea()

---

## Fase 3

### Buffer interno

A biblioteca manterá uma cópia da tela.

Objetivos:

- atualizar apenas caracteres modificados

- reduzir flicker

- melhorar desempenho

---

## Fase 4

### Transições

Funções previstas:

- [ ] slideLeft()

- [ ] slideRight()

- [ ] push()

- [ ] reveal()

---

## Fase 5

### Widgets

Componentes prontos.

Exemplos:

- relógio

- temperatura

- umidade

- barra de progresso

- mensagens

---

# Projeto relacionado

CU205SCPB Smart Clock

A biblioteca será evoluída acompanhando o desenvolvimento do relógio VFD.

Novos recursos serão implementados apenas quando houver uma aplicação prática.

---

# Compatibilidade

Todo código desenvolvido para a versão 1.3.2 continuará funcionando na versão 1.4.0.
