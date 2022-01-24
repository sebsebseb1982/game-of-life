
void setupGame() {
  for (int x = 0; x < SCREEN_WIDTH; x++) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
      game[x][y] = randomBoolean();
    }
  }
}

void logGame() {
  for (int y = 0; y < SCREEN_HEIGHT; y++) {
    Serial.print(y);
    Serial.print(" = ");
    for (int x = 0; x < SCREEN_WIDTH; x++) {
      Serial.print(game[x][y]);
    }
    Serial.println("");
  }
  Serial.println("");
}



int getXCoordinate(int x) {
  if (x == -1) {
    return SCREEN_WIDTH - 1;
  } else if (x == SCREEN_WIDTH) {
    return 0;
  } else {
    return x;
  }
}

int getYCoordinate(int y) {
  if (y == -1) {
    return SCREEN_HEIGHT - 1;
  } else if (y == SCREEN_HEIGHT) {
    return 0;
  } else {
    return y;
  }
}


void loopGame() {
  addRandomCells(getLightSensorValue() * 10);

  for (int x = 0; x < SCREEN_WIDTH; x++) {
    yield();
    for (int y = 0; y < SCREEN_HEIGHT; y++) {

      int aliveSurroundingCellsCount = 0;

      aliveSurroundingCellsCount += game[getXCoordinate(x - 1)][getYCoordinate(y - 1)];
      aliveSurroundingCellsCount += game[getXCoordinate(x - 1)][y];
      aliveSurroundingCellsCount += game[getXCoordinate(x - 1)][getYCoordinate(y + 1)];
      aliveSurroundingCellsCount += game[x][getYCoordinate(y - 1)];
      aliveSurroundingCellsCount += game[x][getYCoordinate(y + 1)];
      aliveSurroundingCellsCount += game[getXCoordinate(x + 1)][getYCoordinate(y - 1)];
      aliveSurroundingCellsCount += game[getXCoordinate(x + 1)][y];
      aliveSurroundingCellsCount += game[getXCoordinate(x + 1)][getYCoordinate(y + 1)];

      if (game[x][y] == 1 && (aliveSurroundingCellsCount == 2 || aliveSurroundingCellsCount == 3)) {
        newGame[x][y] = 1;
      } else if (game[x][y] == 0 && aliveSurroundingCellsCount == 3) {
        newGame[x][y] = 1;
      } else {
        newGame[x][y] = 0;
      }
    }
  }

  for (int x = 0; x < SCREEN_WIDTH; x++) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
      game[x][y] = newGame[x][y];
    }
  }

}

void addRandomCells(int cellsToAdd) {
  for (int i = 0; i < cellsToAdd; i++) {
    game[random(SCREEN_WIDTH)][random(SCREEN_HEIGHT)] = 1;
  }
}
