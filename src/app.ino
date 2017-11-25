
#define cs A2
#define dc D0
#define rst NO_RST_PIN

#include "Adafruit_mfGFX.h"
#include "Adafruit_ST7735.h"
#include "fonts.h"
#include "ArticleScreen.h"
#include "Color.h"
#include "Rectangle.h"
#include "Vec.h"

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst); // hardware spi

// auto background = Color::fromRGB565(ST7735_CASET);

void setup()
{
    // auto background = Color({255,0,255});

    tft.initR(INITR_BLACKTAB);

    // background.lerp(ST7735_WHITE, ST7735_GREEN, 0);

    tft.fillScreen(ST7735_BLACK);
    //    tft.fillScreen(background.asRGB565());

    // rotate the screen appropriately
    tft.setRotation(3);
    tft.setFont(CENTURY_8);

    auto article = ArticleScreen(tft, "Games");
    article.render();

    // Drawing::Rectangle::draw({tft.width() - 20, 20}, {10, tft.height() - 30}, tft, ST7735_WHITE, .5f);

    // tft.setCursor(0, 0);
    // tft.print(rgb.r)

    // tft.setCursor(0, 0);
    // tft.setTextColor(ST7735_WHITE);
    // tft.setTextWrap(true);
    // tft.print("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla");

    // tft.drawLine(0, 0, tft.width() - 1, tft.height() - 1, ST7735_YELLOW);
    // tft.drawLine(tft.width() - 1, 0, 0, tft.height() - 1, ST7735_YELLOW);

    // tft.drawPixel(0, tft.height() / 2, ST7735_GREEN);
}

void loop()
{
    // static double i = 0;
    // static double prev = i;
    // static double delta = .01;

    // Drawing::Rectangle::draw({tft.width() - 20, 20}, {10, tft.height() - 30}, tft, ST7735_BLACK, prev);
    // Drawing::Rectangle::draw({tft.width() - 20, 20}, {10, tft.height() - 30}, tft, ST7735_WHITE, i);

    // prev = i;
    // i += delta;

    // if (i >= 1 || i <= 0) {
    //     delta = -delta;
    // }
}