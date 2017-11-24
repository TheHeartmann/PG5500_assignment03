#pragma once

#include "DisplayRect.h"

class StatRect : public DisplayRect
{
  public:
    StatRect(Adafruit_ST7735 &tft, Drawing::Vec &position, Drawing::Rectangle &dimensions, std::string header, std::string value)
        : DisplayRect(tft, position, dimensions), _header(header), _value(value) {}
    StatRect(Adafruit_ST7735 &tft, Drawing::Vec &position, Drawing::Rectangle &dimensions)
        : DisplayRect(tft, position, dimensions) {}

    void render() override {
        setCursorTopLeft();
        TFTUtils::write(_header, *_tft);
        TFTUtils::write(_value, *_tft);
    }

  private:
    int _fontSizeHeader;
    int _fontSizeContent;
    std::string _header;
    std::string _value;
};