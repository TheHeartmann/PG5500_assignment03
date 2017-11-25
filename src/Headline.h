
#pragma once

#include <string>
#include "TimeUtils.h"

struct Headline
{
    const std::string title,
        source,
        author;
    const tm publishedAt;

    Headline(std::string title, std::string source, std::string author, std::string publishedAt)
        : title(title), source(source), author(author), publishedAt(TimeUtils::timeFromString(publishedAt)) {}
};

static const Headline DEFAULT_HEADLINE = Headline(
    "Adam Helps is a kinder, more Canadian version of TaskRabbit",
    "The Verge",
    "Matthew Hughes",
    "2017-11-24T17:00:00Z");
