#pragma once

struct rgb
{
    byte r;
    byte g;
    byte b;

    rgb &operator=(const rgb &other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
        return *this;
    }

    // conversion functions based on this thread: https://forums.adafruit.com/viewtopic.php?f=19&t=21536
    static uint16_t toRGB565(const rgb color)
    {
        return ((color.r / 8) << 11) | ((color.g / 4) << 5) | (color.b / 8);
    }

    static rgb fromRGB565(const uint16_t color)
    {
        uint32_t bits = (uint32_t)color;
        uint32_t blue = bits & 0x001F;  // 5 bits blue
        uint32_t green = bits & 0x07E0; // 6 bits green
        uint32_t red = bits & 0xF800;   // 5 bits red

        return rgb{(byte)(red << 8), (byte)(green << 5), (byte)(blue << 3)};
    }

    static rgb lerp(const rgb *from, const rgb *to, const double amount)
    {
        // return {255, 0, 0};
        // const auto clampedAmount = constrain(amount, 0, 1);
        return {from->r, from->g, from->b};
    //     return {
    //         from.r + ((to.r - from.r) * clampedAmount),
    //         from.g + ((to.g - from.g) * clampedAmount),
    //         from.b + ((to.b - from.b) * clampedAmount)};
    }
};
