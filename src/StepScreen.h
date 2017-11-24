#pragma once

#include "StatScreen.h"
#include "StatRect.h"

class StepScreen : public StatScreen
{
  public:
    StepScreen(Adafruit_ST7735 &tft)
        : StatScreen(tft, std::string("Steps")) {}

    void render() override
    {
        setCursorTopLeft();
        _tft->setTextColor(_textColor);
        writeHeader();
        for (auto &i : _statRects)
        {
            i.render();
        }
    }

  protected:
    // void initDataRects() override
    // {
    //     for (int i = 0; i < 4; ++i)
    //     {
    //         _dataRects = &_statRects;
    //     }
    // }

    StatRect _statRects[4] {
        StatRect(*_tft, _dataRectPositions[0], _dataRectDimensions, std::string("Header"), std::string("Value")),
        StatRect(*_tft, _dataRectPositions[1], _dataRectDimensions, std::string("Header"), std::string("Value")),
        StatRect(*_tft, _dataRectPositions[2], _dataRectDimensions, std::string("Header"), std::string("Value")),
        StatRect(*_tft, _dataRectPositions[3], _dataRectDimensions, std::string("Header"), std::string("Value"))
    };
};
