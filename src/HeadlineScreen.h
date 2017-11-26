#pragma once

#include "NewsScreen.h"
#include "HeadlineRect.h"
#include <vector>
#include "JsonParser.h"

class HeadlineScreen : public NewsScreen
{
  public:
    HeadlineScreen(Adafruit_ST7735 &tft, std::string category = "Category")
        : NewsScreen(tft, category)
    {
    }

    void headlineHandler(const char *event, const char *data)
    {
        static JsonParser js;
        if (data)
        {
            js.addData(data);
        }
        if (js.isValid())
        {
            _hasData = true;
            auto newData = js.getHeadlines();
            if (newData.size() >= 0)
            {
                _headlines.clear();
                for (auto &i : newData)
                {
                    _headlines.push_back(i);
                }
                _nextIndex = -1;
            } else {
                _headlines.push_back(ERROR_MESSAGE);
            }
        }
    }

    void render() override
    {
        setCursorTopLeft();
        _tft->setTextColor(_textColor);
        _tft->setTextSize(2);
        writeHeader();
        _headlineRect.update(_headlines[_nextIndex]);
    }

    void next()
    {
        incrementIndex();
        _headlineRect.update(_headlines[_nextIndex]);
    }

    bool hasData() const { return _hasData; }

  protected:
    void incrementIndex()
    {
        ++_nextIndex;
        if (_nextIndex >= _headlines.size())
        {
            _nextIndex = 0;
        }
    }
    int _nextIndex = 0;
    bool _hasData = false;
    std::vector<Headline> _headlines{ERROR_MESSAGE};
    HeadlineRect _headlineRect = HeadlineRect(*_tft, _contentPosition, _contentDimensions, _headlines[_nextIndex]);
};
