
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define TFT_CS   5
#define TFT_RST  6
#define TFT_DC   7
#define TFT_MOSI 8
#define TFT_SCK  9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 20);
  tft.println("TFT OK");
}

void loop() {}
