#define cs D4
#define dc D2
#define rst D3

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst); // hardware spi

void setup()
{

    tft.initG();

    tft.fillScreen(ST7735_BLACK);

    tft.setCursor(0, 0);
    tft.setTextColor(ST7735_WHITE);
    tft.setTextWrap(true);
    tft.print("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla");
}

void loop()
{
}