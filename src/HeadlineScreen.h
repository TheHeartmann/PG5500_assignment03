#pragma once

#include "NewsScreen.h"
#include "HeadlineRect.h"

class HeadlineScreen : public NewsScreen
{
  public:
    HeadlineScreen(Adafruit_ST7735 &tft, std::string category = "Category")
        : NewsScreen(tft, category) {}

    void render() override
    {
        setCursorTopLeft();
        _tft->setTextColor(_textColor);
        _tft->setTextSize(2);
        writeHeader();
        _headlineRect.render();
    }

  protected:
    HeadlineRect _headlineRect = HeadlineRect(*_tft, _contentPosition, _contentDimensions);
};
