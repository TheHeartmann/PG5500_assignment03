#pragma once

#include <string>
#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "fonts.h"
#include "Rectangle.h"

class TFTUtils
{
  public:
    static void write(const std::string &text, Adafruit_ST7735 &tft)
    {
        // tft doesn't accept std::string, so we have to c_str() it.
        tft.print(text.c_str());
    }

    // Calculates the maximum possible font size for the text within the given rectangle and with the given font
    static int calculateMaxFontSize(const std::string text, Drawing::Rectangle &dimensions, uint8_t font = CENTURY_8)
    {
        const auto fontDescriptor = TFTUtils::getFontDescriptors(font);
        int length = 0;
        for (auto &i : text) {
            // the sets consist of the last 95 characters of the ascii table--not counting DEL--starting from space
            length += fontDescriptor[i - ' '].width;
        }

        const auto height = fontDescriptor[0].height; // assuming that all chars have the same height

        return constrain(min(dimensions.height / height, dimensions.width / length), 1, 5);
    }

  private:
    static const auto getFontDescriptors(uint8_t font) -> const FontDescriptor *
    {
        switch (font)
        {
#ifdef TIMESNEWROMAN8
        case TIMESNR_8:
            return timesNewRoman_8ptDescriptors;
#endif
#ifdef CENTURYGOTHIC8
        case CENTURY_8:
            return centuryGothic_8ptDescriptors;
#endif
#ifdef ARIAL8
        case ARIAL_8:
            return arial_8ptDescriptors;
#endif
#ifdef COMICSANSMS8
        case COMICS_8:
            return comicSansMS_8ptDescriptors;
#endif
        default:
            return glcdfontDescriptors;
        }
    }
};