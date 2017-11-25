#pragma once

#include <ctime>
#include <string>

static const std::string UTC_FORMAT = "%Y-%m-%dT%TZ";
static const std::string OUTPUT_FORMAT = "%y/%m/%d | %H:%M";


class TimeUtils
{
  public:
    static tm timeFromString(const std::string UTCTimeString)
    {
        struct std::tm tm;
        strptime(UTCTimeString.c_str(), UTC_FORMAT.c_str(), &tm);
        return tm;
    }

    static std::string tmToOutputString(const tm &tm)
    {
        const int stringLength = 17;
        char timeString[stringLength];
        std::strftime(timeString, stringLength, OUTPUT_FORMAT.c_str(), &tm);
        return std::string(timeString);
    }
};