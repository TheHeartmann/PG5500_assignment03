#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Settings.h"

const std::vector<std::string> ACCEPTED_LANGUAGES =
    {
        "en",
        "no",
        ""};

const std::vector<std::string> ACCEPTED_SOURCES =
    {
        "aftenposten",
        "al-jazeera-english",
        "ars-technica",
        "bbc-news",
        "google-news",
        "the-verge",
        "nrk"};

struct QueryManager
{
    QueryManager()
    {
        Particle.function("set_source_1", &QueryManager::setPrimarySource, this);
        Particle.function("set_source_2", &QueryManager::setSecondarySource, this);
        Particle.function("set_language", &QueryManager::setLanguage, this);
        Particle.function("update", &QueryManager::update, this);
    }

    bool verifySource(const String &source)
    {
        return stringInContainer(source, ACCEPTED_SOURCES);
    }

    bool verifyLanguage(const String &lang)
    {
        return stringInContainer(lang, ACCEPTED_LANGUAGES);
    }

    bool stringInContainer(const String &text, std::vector<std::string> container)
    {
        auto str = std::string(text);
        return std::find(container.begin(), container.end(), str) != container.end();
    }

    int setPrimarySource(String source)
    {
        if (!verifySource(source))
        {
            return -1;
        }
        primarySource = source;
        return 0;
    }

    int setSecondarySource(String source)
    {
        if (!verifySource(source))
        {
            return -1;
        }
        secondarySource = source;
        return 0;
    }

    int setLanguage(String newLanguage)
    {
        if (!verifyLanguage(newLanguage))
        {
            return -1;
        }
        language = newLanguage;
        return 0;
    }

    static std::string createQuery()
    {
        std::string queryString = "{\"sources\" : [";
        queryString += "\"" + primarySource + "\", ";
        queryString += "\"" + secondarySource + "\"";
        queryString += "],";

        queryString += "\"apiKey\" : \"" + API_KEY + "\"}";

        return queryString;
    }

    int update(String _)
    {
        Particle.publish("get_headlines", createQuery().c_str(), PRIVATE);
        return 0;
    }
};