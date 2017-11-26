#pragma once

#include <string>
#include "DisplayRect.h"
#include "Drawing.h"

#define HEADER_HEIGHT 0.2
#define HEADER_WIDTH 0.7
#define PAGE_NUMBER_WIDTH 0.3

class NewsScreen : public DisplayRect {
  public:
    NewsScreen(Adafruit_ST7735 &tft, const std::string header)
        : DisplayRect(tft, {0, 0}, {tft.height(), tft.width()}), // swap width and height because the tft is turned on its side
          _header(header) {}

    void setTextColor(uint16_t color) { _textColor = color; }

  protected:
    void writeHeader()
    {
        write(_header);
        underlineHeader();
    }

    void underlineHeader() {
        Drawing::Utils::drawLine({_contentPosition.x, _contentPosition.y - 3}, {_contentPosition.x + _dimensions.width, _contentPosition.y - 3}, *_tft, 0xFA63);
    }

    const std::string _header;
    const Drawing::Rectangle _contentDimensions{_dimensions.width, floor(_dimensions.height * (1 - HEADER_HEIGHT))};
    const Drawing::Vec _contentPosition{_position.x, _position.y + floor(_dimensions.height * HEADER_HEIGHT)};
};