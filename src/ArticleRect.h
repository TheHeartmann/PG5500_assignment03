#pragma once

#include "DisplayRect.h"

#define HEADER_HEIGHT 0.4f

class ArticleRect : public DisplayRect
{
  public:
    StatRect(Adafruit_ST7735 &tft, Drawing::Vec &position, Drawing::Rectangle &dimensions, std::string header, std::string value)
        : DisplayRect(tft, position, dimensions), _header(header), _value(value) {}
    StatRect(Adafruit_ST7735 &tft, Drawing::Vec &position, Drawing::Rectangle &dimensions)
        : DisplayRect(tft, position, dimensions) {}

    void render() override {
        setCursorTopLeft();
        _tft->setTextSize(1);
        write(_header);
        _tft->setTextSize(2);
        _tft->setCursor(_valuePos.x, _valuePos.y);
        write(_value);
    }

  private:
    int _fontSizeHeader;
    int _fontSizeContent;
    std::string _header;
    std::string _value;
    Drawing::Vec _valuePos{_position.x, _position.y + floor(_dimensions.height *HEADER_HEIGHT)};
};
