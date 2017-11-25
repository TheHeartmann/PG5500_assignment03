#pragma once

#include <string>

struct Article
{
    std::string title,
        source,
        description,
        publishedAt;
};

static const Article DEFAULT_ARTICLE = {
    "Which game controllers are worth buying?",
    "Engadget",
    "If you're picking up a game console like the Xbox One X or PlayStation 4 Pro this holiday season, congratulations: You already have a great controller for your new system. Traditionally, third-party gamepads have always been a bit subpar, the kind of thing yo…",
    "2017-11-24T17:00:00Z"};