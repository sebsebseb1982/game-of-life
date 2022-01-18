#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define INVISIBLE_BORDER_SIZE 8
#define GAME_WIDTH SCREEN_WIDTH + (INVISIBLE_BORDER_SIZE * 2)
#define GAME_HEIGHT SCREEN_HEIGHT + (INVISIBLE_BORDER_SIZE * 2)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

bool game[GAME_WIDTH][GAME_HEIGHT];
bool newGame[GAME_WIDTH][GAME_HEIGHT];

int loopCount = 0;
int aliveCells = 0;

bool randomValue() {
  if (random(10) > 1) {
    return true;
  } else {
    return false;
  }
}

void initializeGame() {
  for (int x = 0; x < GAME_WIDTH; x++) {
    for (int y = 0; y < GAME_HEIGHT; y++) {
      game[x][y] = randomValue();
    }
  }
}

void logGame() {
  for (int y = 0; y < GAME_HEIGHT; y++) {
    Serial.print(y);
    Serial.print(" = ");
    for (int x = 0; x < GAME_WIDTH; x++) {
      Serial.print(game[x][y]);
    }
    Serial.println("");
  }
  Serial.println("");
}

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  randomSeed(analogRead(0));
  initializeGame();
  logGame();
  Serial.print("GAME_WIDTH = ");
  Serial.println(GAME_WIDTH);
  Serial.print("GAME_HEIGHT = ");
  Serial.println(GAME_HEIGHT);
}

void displayGame() {
  aliveCells = 0;
  for (int x = 0; x < SCREEN_WIDTH; x++) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
      if (game[x + INVISIBLE_BORDER_SIZE][y + INVISIBLE_BORDER_SIZE] == 1) {
        display.drawPixel(x, y, WHITE);
        aliveCells ++;
      }
    }
  }
  /* display.setCursor(0, 8);
    display.print(aliveCells);*/
}

void gameLoop() {
  //Serial.println(F("gameLoop()"));

  for (int x = 0; x < GAME_WIDTH; x++) {
    yield();
    for (int y = 0; y < GAME_HEIGHT; y++) {

      int aliveSurroundingCellsCount = 0;

      if (x > 0 && y > 0) {
        aliveSurroundingCellsCount += game[x - 1][y - 1];
      }
      if (x > 0) {
        aliveSurroundingCellsCount += game[x - 1][y];
      }
      if (x > 0 && y < GAME_HEIGHT - 1) {
        aliveSurroundingCellsCount += game[x - 1][y + 1];
      }
      if (y > 0) {
        aliveSurroundingCellsCount += game[x][y - 1];
      }
      if (y < GAME_HEIGHT - 1) {
        aliveSurroundingCellsCount += game[x][y + 1];
      }
      if (x < GAME_WIDTH - 1 && y > 0) {
        aliveSurroundingCellsCount += game[x + 1][y - 1];
      }
      if (x < GAME_WIDTH - 1) {
        aliveSurroundingCellsCount += game[x + 1][y];
      }
      if (x < GAME_WIDTH - 1 && y < GAME_HEIGHT - 1) {
        aliveSurroundingCellsCount += game[x + 1][y + 1];
      }

      if (game[x][y] == 1 && (aliveSurroundingCellsCount == 2 || aliveSurroundingCellsCount == 3)) {
        newGame[x][y] = 1;
      } else if (game[x][y] == 0 && aliveSurroundingCellsCount == 3) {
        newGame[x][y] = 1;
      } else {
        newGame[x][y] = 0;
      }
    }
  }

  for (int x = 0; x < GAME_WIDTH; x++) {
    for (int y = 0; y < GAME_HEIGHT; y++) {
      game[x][y] = newGame[x][y];
    }
  }

}

void addRandomLife() {
  int maxNewCell = (30000 - aliveCells) / 100;
  for (int i = 0; i < random(maxNewCell); i++) {
    game[random(GAME_WIDTH)][random(GAME_HEIGHT)] = 1;
  }
}

void loop() {
  addRandomLife();
  gameLoop();
  display.clearDisplay();

  displayGame();
  /*   display.setCursor(0, 20);
    display.print(F("Test"));
  */
  display.display();
  //Serial.println(F("coucou"));
  //logGame();
  loopCount++;
}
