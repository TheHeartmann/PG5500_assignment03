#pragma once

#include <string>

class StringUtils
{
  public:
    static const std::string truncate(const std::string &text, int maxLength, const std::string &delimiter = " ")
    {
        if (text.length() <= maxLength) {
            return text;
        }
        auto truncated = text.substr(0, maxLength);
        auto lastDelimiter = truncated.find_last_of(delimiter);
        return truncated.substr(0, lastDelimiter) + " ...";
    }
};