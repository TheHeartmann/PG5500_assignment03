#pragma once

#include "Vec.h"
#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "TFTUtils.h"

class DisplayElement
{
  public:
    DisplayElement(Adafruit_ST7735 &tft) : _tft(&tft), _position({0, 0}) {}
    DisplayElement(Adafruit_ST7735 &tft, Drawing::Vec position) : _tft(&tft), _position(position) {}
    virtual void render() = 0;

  protected:
    void write(const std::string text)
    {
        TFTUtils::write(text, *_tft);
    }
    Adafruit_ST7735 *_tft;
    Drawing::Vec _position;
};