#pragma once

#include "Vec.h"
#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "TFTUtils.h"
#include "Settings.h"

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

    void write(const std::string text, uint16_t color)
    {
        _tft->setTextColor(color);
        TFTUtils::write(text, *_tft);
        _tft->setTextColor(_textColor);
    }

    uint16_t _textColor = TEXT_COLOR;
    uint16_t _backgroundColor = BACKGROUND_COLOR;
    uint16_t _highlightColor = HIGHLIGHT_COLOR;
    Adafruit_ST7735 *_tft;
    Drawing::Vec _position;
};