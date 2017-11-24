#pragma once

#include "Adafruit_mfGFX.h"  // Core graphics library
#include "Adafruit_ST7735.h" // Hardware-specific library
#include "Vec.h"

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

        drawLine(topLeft, topRight, tft, color);       // top
        drawLine(bottomLeft, bottomRight, tft, color); // bottom
        drawLine(topLeft, bottomLeft, tft, color);     // left
        drawLine(topRight, bottomRight, tft, color);   // right

        fillPercentage = constrain(fillPercentage, 0, 1);

        if (fillPercentage == 0)
            return;

        const auto fillWidth = round(rect.width * fillPercentage);

        drawFilled(pos, {fillWidth, rect.height}, tft, color);
    }

    static void drawLine(const Vec &start, const Vec &end, Adafruit_ST7735 &tft, const uint16_t color)
    {
        tft.drawLine(start.x, start.y, end.x, end.y, color);
    }

    static void drawFilled(const Vec &pos, const Rectangle &rect, Adafruit_ST7735 &tft, const uint16_t color)
    {
        tft.fillRect(pos.x, pos.y, rect.width, rect.height, color);
    }
};
