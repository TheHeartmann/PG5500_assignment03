
#pragma once

#include <string>
#include "TimeUtils.h"
#include "StringUtils.h"

struct Headline
{
    const std::string title,
        source,
        author, publishedAt;

    Headline(std::string title, std::string source, std::string author, std::string publishedAt)
        : title(title),
          source(source),
          author(author),
          publishedAt(TimeUtils::tmToOutputString(TimeUtils::timeFromString(publishedAt))) {}

    Headline(const char *title, const char *source, const char *author, const char *publishedAt)
        : title(StringUtils::parseJsonOutput(title)),
          source(StringUtils::parseJsonOutput(source)),
          author(StringUtils::parseJsonOutput(author)),
          publishedAt(StringUtils::parseTimeString(publishedAt)) {}

    static std::string parseTimeString(std::string &text)
    {
    }
};

static const Headline DEFAULT_HEADLINE = Headline(
    "Adam Helps is a kinder, more Canadian version of TaskRabbit",
    "The Verge",
    "Matthew Hughes",
    "2017-11-24T17:00:00Z");
