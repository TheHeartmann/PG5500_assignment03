
#pragma once

#include <string>
#include "TimeUtils.h"
#include "StringUtils.h"

struct Headline
{
    const std::string title,
        source,
        author,
        publishedAt;

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
};

static const Headline DEFAULT_HEADLINE = Headline(
    "Gathering data. Please wait ...",
    PRODUCT_NAME.c_str(),
    "Thomas Hartmann",
    Time.format(Time.now(), UTC_FORMAT.c_str()));

static const Headline ERROR_MESSAGE = Headline(
    "Parsing the input failed. Try again or use fewer sources if it still fails.",
    PRODUCT_NAME.c_str(),
    "Thomas Hartmann",
    Time.format(Time.now(), UTC_FORMAT.c_str()));
