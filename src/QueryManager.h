#pragma once

#include <string>
#include <vector>
#include <algorithm>

int carouselRate = 10000;
int updateRate = 60000; // maximum allowed time
String primarySource = "ars-technica";
String secondarySource = "the-verge";
String language = "en";

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
        Particle.function("update", &QueryManager::update, this);
    }

    bool verifySource(const String &source)
    {
        return stringInContainer(source, ACCEPTED_SOURCES);
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

    static std::string createQuery()
    {
        std::string queryString = "{\"sources\" : [";
        queryString += "\"" + primarySource + "\", ";
        queryString += "\"" + secondarySource + "\"";
        queryString += "],";

        queryString += "\"apiKey\" : \"6f4590c7190e4a4c87292fb463ef04f7\"}";

        return queryString;
    }

    int update(String _)
    {
        Particle.publish("get_headlines", createQuery().c_str(), PRIVATE);
        return 0;
    }
};