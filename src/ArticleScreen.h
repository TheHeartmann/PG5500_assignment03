#pragma once

#include "NewsScreen.h"
#include "ArticleRect.h"

class ArticleScreen : public NewsScreen
{
  public:
    ArticleScreen(Adafruit_ST7735 &tft, std::string category = "Category")
        : NewsScreen(tft, category) {}

    void render() override
    {
        setCursorTopLeft();
        _tft->setTextColor(_textColor);
        _tft->setTextSize(2);
        writeHeader();
        _articleRect.render();
    }

  protected:
    ArticleRect _articleRect = ArticleRect(*_tft, _contentPosition, _contentDimensions);
};