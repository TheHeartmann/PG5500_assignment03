#pragma once

#include "DisplayRect.h"
#include "Headline.h"
#include "TimeUtils.h"

#define HEADER_HEIGHT 0.1

class HeadlineRect : public DisplayRect
{
  public:
    HeadlineRect(Adafruit_ST7735 &tft, Drawing::Vec position, Drawing::Rectangle dimensions, Headline headline = DEFAULT_HEADLINE)
        : DisplayRect(tft, position, dimensions), _headline(headline) {}

    void render() override
    {
        setCursorTopLeft();
        _tft->setTextSize(1);
        _tft->setTextWrap(true);
        write(TimeUtils::tmToOutputString(_headline.publishedAt) + "\n\n");
        write(_headline.title + "\n\n");
        // _tft->setCursor(_position.x, (_position.y + _dimensions.height) - floor(.3 * _dimensions.height));
        write("By " + _headline.author + "\nfor " + _headline.source);
        // write(_headline.title + "\n" + _headline.source + " | " + _headline.publishedAt + "\n" + _headline.description);
    }

  private:
    Headline _headline;
};

