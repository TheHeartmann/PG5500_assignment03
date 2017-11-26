#pragma once

#include <cmath>
#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "Vec.h"
#include "Drawing.h"

namespace Drawing
{
    struct Rectangle
    {
        int width;
        int height;

        static void draw(const Rectangle &rect, const Vec &pos, Adafruit_ST7735 &tft, const uint16_t color, double fillPercentage = 0)
        {
            Vec topLeft = {pos.x, pos.y};
            Vec topRight = {pos.x + rect.width, pos.y};
            Vec bottomLeft = {pos.x, pos.y + rect.height};
            Vec bottomRight = {pos.x + rect.width, pos.y + rect.height};

            Utils::drawLine(topLeft, topRight, tft, color);       // top
            Utils::drawLine(bottomLeft, bottomRight, tft, color); // bottom
            Utils::drawLine(topLeft, bottomLeft, tft, color);     // left
            Utils::drawLine(topRight, bottomRight, tft, color);   // right

            fillPercentage = constrain(fillPercentage, 0, 1);

            if (fillPercentage == 0)
                return;

            const int fillWidth = std::round(rect.width * fillPercentage);

            drawFilled(pos, {fillWidth, rect.height}, tft, color);
        }

        static void drawFilled(const Vec &pos, const Rectangle &rect, Adafruit_ST7735 &tft, const uint16_t color)
        {
            tft.fillRect(pos.x, pos.y, rect.width, rect.height, color);
        }
    };
};