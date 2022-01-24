Screen currentScreen;
int currentScreenIndex;

Screen screens[] = {
  GAME_OF_LIFE,
  LIGHT_SENSOR
};

void setupScreen() {
  currentScreen = GAME_OF_LIFE;
  currentScreenIndex = 0;
}

void header(String name) {
  display.clearDisplay();
  display.setCursor(0, 8);
  display.print(name);
}

void updateScreen() {
  computeMenuPageControls();
  
  display.clearDisplay();

  if (currentScreen == GAME_OF_LIFE) {
    displayGameOfLifeScreen();
  } else if (currentScreen == LIGHT_SENSOR) {
    displayLightSensorScreen();
  }

  display.display();
 
}

void computeMenuPageControls() {

  int nbScreens = sizeof(screens) / sizeof(Screen);

  if (buttonsStatus.left && !buttonsStatus.leftAlreadyTreated) {
    currentScreenIndex --;
    buttonsStatus.leftAlreadyTreated = true;
  } else if (buttonsStatus.right && !buttonsStatus.rightAlreadyTreated) {
    currentScreenIndex ++;
    buttonsStatus.rightAlreadyTreated = true;
  }

  if (currentScreenIndex == -1) {
    currentScreenIndex = nbScreens - 1;
  } else {
    currentScreenIndex = currentScreenIndex % nbScreens;
  }

  currentScreen = screens[currentScreenIndex];
}
