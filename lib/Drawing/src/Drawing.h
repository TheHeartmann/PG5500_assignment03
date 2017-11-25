#pragma once

#include "Adafruit_mfGFX.h"  // Core graphics library
#include "Adafruit_ST7735.h" // Hardware-specific library
#include "Vec.h"
#include "Rectangle.h"

namespace Drawing {
    class Utils
    {
    public:
        static void drawLine(const Vec &start, const Vec &end, Adafruit_ST7735 &tft, const uint16_t color)
        {
            tft.drawLine(start.x, start.y, end.x, end.y, color);
        }
    };
};