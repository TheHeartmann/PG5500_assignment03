#pragma once

#include <string>
#include "DisplayRect.h"
#include "Drawing.h"
#include "Settings.h"

static const double LOGO_HEIGHT = 0.6;

class StartupScreen : public DisplayRect {
  public:
    StartupScreen(Adafruit_ST7735 &tft)
        : DisplayRect(tft, {0, 0}, {tft.height(), tft.width()}) {}

    void setTextColor(uint16_t color) { _textColor = color; }

    void render() override {
        _tft->setTextSize(3);
        write(PRODUCT_NAME, _textColor);
    }

  protected:

    const std::string _header;
    uint16_t _textColor = HIGHLIGHT_COLOR;
    const Drawing::Rectangle _loadingBarRect{_dimensions.width, floor(_dimensions.height *(1 - LOGO_HEIGHT))};
    const Drawing::Vec _contentPosition{_position.x, _position.y + floor(_dimensions.height * LOGO_HEIGHT)};
};