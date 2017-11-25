#pragma once

// #include <vector>
#include <cmath>
#include <string>
#include "DisplayRect.h"

#define HEADER_HEIGHT 0.2f
#define RECT_HEIGHT 0.4f
#define RECT_WIDTH 0.5f

// base class for stat screens. specifies layouts etc.
class StatScreen : public DisplayRect
{
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
    uint16_t _textColor = ST7735_WHITE;
    Drawing::Rectangle _dataRectDimensions = {floor(_dimensions.width * RECT_WIDTH), floor(_dimensions.height *RECT_HEIGHT)};
    Drawing::Vec _dataRectPositions[4] = {
        {_position.x, floor(_position.y + _dimensions.height * HEADER_HEIGHT)},
        {floor(_position.x + _dimensions.width * RECT_WIDTH), floor(_position.y + _dimensions.height * HEADER_HEIGHT)},
        {_position.x, floor(_position.y + _dimensions.height * HEADER_HEIGHT + _dimensions.height * RECT_HEIGHT)},
        {floor(_position.x + _dimensions.width * RECT_WIDTH), floor(_position.y + _dimensions.height * HEADER_HEIGHT + _dimensions.height * RECT_HEIGHT)}};
};