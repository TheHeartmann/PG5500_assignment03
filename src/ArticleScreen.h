#pragma once

#include "NewsScreen.h"

class ArticleScreen {
  public:
    ArticleScreen(Adafruit_ST7735 &tft, std::string category = "Placeholder")
        : NewsScreen(tft, category) {}

    void render() override
    {
        setCursorTopLeft();
        _tft->setTextColor(_textColor);
        // _tft->setTextSize(TFTUtils::calculateMaxFontSize(_header, _dimensions));
        _tft->setTextSize(2);
        writeHeader();
        for (auto &i : _statRects)
        {
            i.render();
        }
    }

  protected:
    StatRect _statRects[4] {
        StatRect(*_tft, _dataRectPositions[0], _dataRectDimensions, "Today", "9,852"),
        StatRect(*_tft, _dataRectPositions[1], _dataRectDimensions, "Goal", "20,000"),
        StatRect(*_tft, _dataRectPositions[2], _dataRectDimensions, "Average", "15,000"),
        StatRect(*_tft, _dataRectPositions[3], _dataRectDimensions, "Progress", "49%")
    };
};