#pragma once

#include <string>
#include "DisplayRect.h"

#define HEADER_HEIGHT 0.2
#define HEADER_WIDTH 0.7
#define PAGE_NUMBER_WIDTH 0.3

class NewsScreen : public DisplayRect {
  public:
    StatScreen(Adafruit_ST7735 &tft, const std::string header)
        : DisplayRect(tft, {0, 0}, {tft.width(), tft.height()}),
          _header(header) {}

    void setTextColor(uint16_t color) { _textColor = color; }

  protected:
    void writeHeader()
    {
        write(_header);
    }

    const std::string _header;
    const Drawing::Rectangle contentDimensions = {_dimensions.width, floor(_dimensions.height * (1 - HEADER_HEIGHT))};
    uint16_t _textColor = ST7735_WHITE;
};