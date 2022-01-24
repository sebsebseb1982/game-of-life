#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "buttons.h"
#include "screen.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

bool game[SCREEN_WIDTH][SCREEN_HEIGHT];
bool newGame[SCREEN_WIDTH][SCREEN_HEIGHT];

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();

  setupGFX();
  setupButtons();
  setupScreen();
  setupGame();
  logGame();
}

void loop() {
  loopButtons();
  loopGame();

  updateScreen();
}
