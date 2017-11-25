#pragma once

#include "DisplayRect.h"
#include "Article.h"

#define HEADER_HEIGHT 0.1

class ArticleRect : public DisplayRect
{
  public:
    ArticleRect(Adafruit_ST7735 &tft, Drawing::Vec position, Drawing::Rectangle dimensions, Article article = DEFAULT_ARTICLE)
        : DisplayRect(tft, position, dimensions), _article(article) {}

    void render() override
    {
        setCursorTopLeft();
        _tft->setTextSize(1);
        _tft->setTextWrap(true);
        write(_article.title + "\n" + _article.source + " | " + _article.publishedAt + "\n" + _article.description);
    }

  private:
    Article _article;
    // Drawing::Vec _descriptionPos{_position.x, _position.y + floor(_dimensions.height *HEADER_HEIGHT)};
};
