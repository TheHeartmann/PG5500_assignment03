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
    HeadlineRect(Adafruit_ST7735 &tft, Drawing::Vec position, Drawing::Rectangle dimensions, const Headline &headline = ERROR_MESSAGE)
        : DisplayRect(tft, position, dimensions), _headline(&headline) {}

    void render() override
    {
        render(_textColor, _highlightColor);
    }

    void update(const Headline &newHeadline)
    {
        fill(_backgroundColor);
        // render(_backgroundColor, _backgroundColor);
        _headline = &newHeadline;
        render();
    }

  private:

    void render(uint16_t color, uint16_t hightlightColor)
    {
        setCursorTopLeft();
        _tft->setTextSize(1);
        _tft->setTextWrap(true);
        write(_headline->publishedAt + "\n\n", color);
        write(StringUtils::truncate(_headline->title, MAX_HEADLINE_LENGTH) + "\n\n", color);
        write("By " + _headline->author + "\n", color);
        write("for ");
        write(_headline->source + "\n\n", hightlightColor);
    }

    const Headline * _headline;
};

