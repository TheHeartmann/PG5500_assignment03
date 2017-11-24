#pragma once

#include <string>
#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h" // Hardware-specific library

class GenericScreen
{
  public:
    GenericScreen(Adafruit_ST7735 &tft) : tft(&tft) {}
    virtual void draw() = 0;

  protected:
    void drawHeader() {
        tft->setCursor(0, 0);
        tft->setTextColor(ST7735_WHITE);
        tft->setTextWrap(true);
        write(header);
    }
    void write(const std::string &text) {
        // tft doesn't accept std::string, so we have to c_str() it.
        tft->print(text.c_str());
    }
    std::string header;



    Adafruit_ST7735 *tft;
};