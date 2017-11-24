#pragma once


#include "GenericScreen.h"

class StatsScreen : public GenericScreen
{
  public:
    StatsScreen(Adafruit_ST7735 &tft) : GenericScreen(tft) {
        header = "Stats screen for Thomas";
    }

    void draw() {
        GenericScreen::drawHeader();
    }

};