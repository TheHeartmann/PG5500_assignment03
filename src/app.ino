#define cs A2
#define dc D0
#define rst NO_RST_PIN

#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "HeadlineScreen.h"
#include "Settings.h"
#include "QueryManager.h"

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);
HeadlineScreen display = HeadlineScreen(tft, "Headlines");
Timer carouselTimer(CAROUSEL_RATE, next);
Timer updateTimer(UPDATE_RATE, update);
QueryManager qm;

void setup()
{
    Particle.variable("source_1", primarySource);
    Particle.variable("source_2", secondarySource);
    Particle.variable("language", language);
    Particle.subscribe("hook-response/get_headlines", headlineHandler, MY_DEVICES);

    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);
    // rotate the screen appropriately
    tft.setRotation(3);

    carouselTimer.start();
    updateTimer.start();
    update();

    display.render();
}

void headlineHandler(const char *event, const char *data)
{
    display.headlineHandler(event, data);
}

void next()
{
    display.next();
}

void update()
{
    static int cycleCount = 0;
    if (cycleCount == 0)
    {
        qm.update("");
    }
    cycleCount = (cycleCount + 1) % 5;
}