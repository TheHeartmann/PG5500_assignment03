#pragma once

#include "rgb.h"

namespace Colors
{
    // class to store and convert between various representations of a color
    // works with rgb internally
    class Color
    {
    public:
        Color(const rgb color) : _rgb(color)
        {
        }

        static Color fromRGB565(uint16_t color)
        {
            return Color(rgb::fromRGB565(color));
        }

        uint16_t asRGB565() const
        {
            return rgb::toRGB565(_rgb);
        }

        void lerp(const uint16_t from, const uint16_t to, const double amount)
        {
            const auto fromRgb = rgb::fromRGB565(from);
            const auto toRgb = rgb::fromRGB565(to);
            const auto clampedAmount = constrain(amount, 0, 1);
            _rgb.r = fromRgb.r + (toRgb.r - fromRgb.r) * clampedAmount;
            _rgb.g = fromRgb.g + (toRgb.g - fromRgb.g) * clampedAmount;
            _rgb.b = fromRgb.b + (toRgb.b - fromRgb.b) * clampedAmount;
            // _rgb.r = 255;
            // _rgb.g = 255;
            // _rgb.b = 255;
            // _rgb = rgb::lerp(&fromRgb, &toRgb, amount);
        }

    private:
        rgb _rgb;
    };
};