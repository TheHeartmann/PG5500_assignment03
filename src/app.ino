
#define cs A2
#define dc D0
#define rst NO_RST_PIN

#include <ArduinoJson.h>
#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "fonts.h"
#include "HeadlineScreen.h"
#include "Color.h"
#include "Rectangle.h"
#include "Vec.h"
#include "JsonString.h"

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst); // hardware spi

void setup()
{
    // auto background = Color({255,0,255});
    Serial.begin(9600);

    Particle.subscribe("hook-response/get_headlines", myHandler, MY_DEVICES);
    tft.initR(INITR_BLACKTAB);

    // background.lerp(ST7735_WHITE, ST7735_GREEN, 0);

    tft.fillScreen(ST7735_BLACK);
    //    tft.fillScreen(background.asRGB565());

    // rotate the screen appropriately
    tft.setRotation(3);
    tft.setFont(CENTURY_8);

    auto headline = HeadlineScreen(tft, "Headlines");
    headline.render();

    // Drawing::Rectangle::draw({tft.width() - 20, 20}, {10, tft.height() - 30}, tft, ST7735_WHITE, .5f);
}

void loop()
{

    // std::string ds = "{\"sources\" : [\"bbc-news\", \"ars-technica\", \"nrk\"], \"apiKey\" : \"6f4590c7190e4a4c87292fb463ef04f7\"}";
    // std::string ds = "{\"sources\" : [\"bbc-news\", \"ars-technica\", \"the-verge\"], \"apiKey\" : \"6f4590c7190e4a4c87292fb463ef04f7\"}";
    std::string ds = "{\"sources\" : [\"ars-technica\", \"the-verge\"], \"apiKey\" : \"6f4590c7190e4a4c87292fb463ef04f7\"}";
    // std::string ds = "{\"sources\" : [\"nrk\", \"the-verge\"], \"apiKey\" : \"6f4590c7190e4a4c87292fb463ef04f7\"}";
    // Trigger the integration
    Particle.publish("get_headlines", ds.c_str(), PRIVATE);
    // Wait 60 seconds
    delay(30000);
}

int i = 0;

void myHandler(const char *event, const char *data)
{
    static JsonString js;
    if (data)
    {
        js.addData(data);
    }
    if (js.isValid())
    {
        auto headlines = js.getHeadlines();

        for (auto &i : headlines)
        {
            Serial.printlnf("%s: %s (%s, %s)", i.publishedAt.c_str(), i.title.c_str(), i.author.c_str(), i.source.c_str());
        }
    }
}
