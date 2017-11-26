#pragma once

#include <string>
#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "DisplayElement.h"
#include "Rectangle.h"

class DisplayRect : public DisplayElement
{
  public:
    DisplayRect(Adafruit_ST7735 &tft, Drawing::Vec position, Drawing::Rectangle dimensions)
        : DisplayElement(tft, position), _dimensions(dimensions) {}

    void clear()
    {
        fill(_backgroundColor);
    }

  protected:
    void setCursorTopLeft() {
        _tft->setCursor(_position.x, _position.y);
    }

    void fill(uint16_t color)
    {
        _tft->fillRect(_position.x, _position.y, _dimensions.width, _dimensions.height, color);
    }

    Drawing::Rectangle _dimensions;
};