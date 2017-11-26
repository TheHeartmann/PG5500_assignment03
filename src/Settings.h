#pragma once

#include "Adafruit_ST7735.h"

static const uint16_t HIGHLIGHT_COLOR = 0xFA63;
static const uint16_t BACKGROUND_COLOR = ST7735_BLACK;
static const uint16_t TEXT_COLOR = ST7735_WHITE;

static const std::string PRODUCT_NAME = "Harticle Photom";

const int CAROUSEL_RATE = 10000;
const int UPDATE_RATE = 60000;

static const std::string API_KEY = "6f4590c7190e4a4c87292fb463ef04f7"