#pragma once

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
#include "JsonParser.h"
#include "Settings.h"
#include "QueryManager.h"
#include "StartupScreen.h"

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst); // hardware spi

HeadlineScreen display = HeadlineScreen(tft, "Headlines");
// auto startup = StartupScreen(tft);
Timer carouselTimer(CAROUSEL_RATE, next);
Timer updateTimer(UPDATE_RATE, update);
QueryManager qm;

void setup()
{
    Particle.variable("source_1", primarySource);
    Particle.variable("source_2", secondarySource);
    Particle.variable("language", language);

    carouselTimer.start();
    updateTimer.start();
    update();

    Particle.subscribe("hook-response/get_headlines", headlineHandler, MY_DEVICES);
    tft.initR(INITR_BLACKTAB);

    tft.fillScreen(ST7735_BLACK);

    // rotate the screen appropriately
    tft.setRotation(3);

    display.render();
    // init();

    // Drawing::Rectangle::draw({tft.width() - 20, 20}, {10, tft.height() - 30}, tft, ST7735_WHITE, .5f);
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

// void init(){
//     startup.render();
//     initTimer.start();
// }

// void renderDisplay() {
//     if (!display.hasData()) {
//         return;
//     }
//     startup.clear();
//     initTimer.stop();
//     display.render();
// }