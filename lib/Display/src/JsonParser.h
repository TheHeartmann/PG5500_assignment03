#pragma once

#include <string>
#include "StringUtils.h"
#include "Headline.h"
#include <vector>
#include <ArduinoJson.h>
#include "TimeUtils.h"
#include <algorithm>

// a simple struct for parsing separate chunks of json data to one object.
// does not account for potential stray brace characters in the data
struct JsonParser
{
  public:
    JsonParser() {}

    JsonParser(const std::string data) { addData(data); }

    bool isValid() const { return _isValid && _openedBraces > 0 && _closedBraces > 0; }

    std::string getData() const { return _data; }

    void addData(const std::string data)
    {
        _openedBraces += StringUtils::countOccurences(data, "{");
        _closedBraces += StringUtils::countOccurences(data, "}");
        _data += data;
        _isValid = _openedBraces == _closedBraces;
    }

    // note that this clears the object to avoid parsing issues
    std::vector<Headline> getHeadlines()
    {
        DynamicJsonBuffer buffer;
        std::vector<char> charVec(_data.begin(), _data.end());
        charVec.push_back('\0');
        JsonObject &json = buffer.parseObject(&charVec[0]);
        std::vector<Headline> headlines;

        if (json.success())
        {
            JsonArray &articles = json["articles"];

            for (JsonObject &obj : articles)
            {
                const char *title = obj["title"];
                const char *source = obj["source"]["name"];
                const char *author = obj["author"];
                const char *publishedAt = obj["publishedAt"];
                headlines.push_back(Headline(title, source, author, publishedAt));
            }
        }
        clear();
        return headlines;
    }

    void clear()
    {
        _data.clear();
        _openedBraces = 0;
        _closedBraces = 0;
        _isValid = false;
    }

  private:
    std::string _data;
    bool _isValid = false;
    size_t _openedBraces;
    size_t _closedBraces;
};