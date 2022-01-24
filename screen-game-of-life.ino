int aliveCells = 0;

void displayGameOfLifeScreen() {
  if (buttonsStatus.middle && !buttonsStatus.middleAlreadyTreated) {
    setupGame();
    buttonsStatus.middleAlreadyTreated = true;
  }
  
  aliveCells = 0;
  for (int x = 0; x < SCREEN_WIDTH; x++) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
      if (game[x][y] == 1) {
        display.drawPixel(x, y, WHITE);
        aliveCells ++;
      }
    }
  }
}
