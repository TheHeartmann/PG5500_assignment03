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

  protected:
    void setCursorTopLeft() {
        _tft->setCursor(_position.x, _position.y);
    }

    Drawing::Rectangle _dimensions;
};