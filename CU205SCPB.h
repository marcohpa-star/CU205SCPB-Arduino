#ifndef CU205SCPB_H
#define CU205SCPB_H

#include <Arduino.h>
#include <Print.h>

#define CU205SCPB_VERSION "1.3.2"

class CU205SCPB : public Print
{
public:

    // =========================================================
    // Informações do display
    // =========================================================

    static const uint8_t DISPLAY_WIDTH  = 20;
    static const uint8_t DISPLAY_HEIGHT = 1;


    // =========================================================
    // Construtor e inicialização
    // =========================================================

    CU205SCPB(const uint8_t p[8], uint8_t wr, uint8_t cs);

    bool begin();


    // =========================================================
    // Controle básico do display
    // =========================================================

    void clear();

    void home();

    void setCursor(uint8_t pos);

    void setBrightness(uint8_t value);


    // =========================================================
    // Controle do cursor
    // =========================================================

    void cursorOn();

    void cursorOff();

    void backspace();

    void tab();

    void carriageReturn();

    uint8_t getCursorPosition();


    // =========================================================
    // Modos de operação
    // =========================================================

    void autoReturnMode();

    void overwriteMode();

    void scrollMode();


    // =========================================================
    // Efeitos e funções de texto
    // =========================================================

    void typeWriter(const char *text, uint16_t speed);

    void typeWriterCentered(const char *text, uint16_t speed);

    void center(const char *text);

    void blinkText(const char *text,
                   uint16_t interval,
                   uint8_t times);


    // =========================================================
    // Rolagem de texto
    // =========================================================

    void scrollText(const char *text,
                    uint16_t speed = 250,
                    bool repeat = false,
                    uint16_t pause = 1000);

    void marquee(const char *text,
                 uint16_t speed,
                 bool repeat,
                 uint16_t pause);


    // =========================================================
    // Barra de progresso
    // =========================================================

    void progressBar(uint8_t percent);


    // =========================================================
    // Interface Print
    // =========================================================

    size_t write(uint8_t c) override;


private:

    // =========================================================
    // Pinos de comunicação
    // =========================================================

    uint8_t _d[8];

    uint8_t _wr;

    uint8_t _cs;


    // =========================================================
    // Estado interno
    // =========================================================

    // Posição atual do cursor mantida pela biblioteca
    uint8_t _cursorPos;


    // =========================================================
    // Comunicação interna
    // =========================================================

    void sendByte(uint8_t value);
};

#endif