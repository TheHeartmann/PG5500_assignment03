#pragma once

#include <string>
#include "TimeUtils.h"

class StringUtils
{
  public:
    static const std::string truncate(const std::string &text, int maxLength, const std::string &delimiter = " ", const std::string &terminator = " ...")
    {
        if (text.length() <= maxLength)
        {
            return text;
        }
        auto truncated = text.substr(0, maxLength);
        auto lastDelimiter = truncated.find_last_of(delimiter);
        return truncated.substr(0, lastDelimiter) + terminator;
    }

    static size_t countOccurences(const std::string &text, std::string &&substring, int offset = 0)
    {
        size_t count;
        int pos = offset;
        while ((pos = text.find(substring, pos)) != std::string::npos)
        {
            pos += substring.length();
            count++;
        }
        return count;
    }

    static std::string parseJsonOutput(const char *text)
    {
        if (text == NULL)
        {
            return "N/A";
        }
        return std::string(text);
    }

    static std::string parseTimeString(const char *text)
    {
        if (text == NULL) {
            return "No time specified";
        }

        return TimeUtils::tmToOutputString(TimeUtils::timeFromString(std::string(text)));
    }
};