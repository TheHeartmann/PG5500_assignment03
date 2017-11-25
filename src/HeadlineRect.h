#pragma once

#include "DisplayRect.h"
#include "Headline.h"
#include "TimeUtils.h"
#include "StringUtils.h"

#define HEADER_HEIGHT 0.1
#define MAX_HEADLINE_LENGTH 100

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
        write(StringUtils::truncate(_headline.title, MAX_HEADLINE_LENGTH) + "\n\n");
        write("By " + _headline.author + "\n");
        write("for ");
        writeDifferentColor(_headline.source + "\n\n", 0xFA63);
    }

  private:
    Headline _headline;
};

