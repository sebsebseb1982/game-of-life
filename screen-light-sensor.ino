const int BAR_WIDTH = 128;
const int BAR_HEIGHT = 7;

void displayLightSensorScreen() {
  header("Light sensor");
  
  displayLightSensorValue();
}

void displayLightSensorValue() {
  int barPositionX = 0;
  int barPositionY = 20;

  display.setTextSize(1);

  displayBar(
    barPositionX,
    barPositionY,
    BAR_WIDTH - barPositionX,
    BAR_HEIGHT,
    getLightSensorValue()
  );
}
