#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <DHT.h>

#define TFT_CS   5
#define TFT_RST  6
#define TFT_DC   7
#define TFT_MOSI 8
#define TFT_SCK  9

#define DHTPIN   4
#define DHTTYPE  DHT22
#define MQ2_PIN  A0

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(0, 0);  tft.print("Temp:");
  tft.setCursor(0, 20); tft.print("Hum:");
  tft.setCursor(0, 40); tft.print("Gas:");
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int gas = analogRead(MQ2_PIN);

  tft.setTextColor(ST77XX_YELLOW, ST77XX_BLACK);

  tft.setCursor(40, 0);
  if (isnan(t)) tft.print("ERR     ");
  else { tft.print(t, 1); tft.print(" C   "); }

  tft.setCursor(40, 20);
  if (isnan(h)) tft.print("ERR     ");
  else { tft.print(h, 1); tft.print(" %   "); }

  tft.setCursor(40, 40);
  tft.print(gas);
  tft.print("    ");

  delay(2000);
}
