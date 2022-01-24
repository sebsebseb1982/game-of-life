const int PADDING = 2;

void setupGFX() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void displayBar(
  int x,
  int y,
  int width,
  int height,
  float value
) {
  display.drawRect(
    x,
    y,
    width,
    height,
    WHITE
  );

  display.fillRect(
    x + PADDING,
    y + PADDING,
    (width - 2 * PADDING) * value,
    height - 2 * PADDING,
    WHITE
  );
}

void displayCenteredText(String textToDisplay) {
  display.setTextSize(2);

  int x = SCREEN_WIDTH / 2;
  int y = SCREEN_HEIGHT / 2;

  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(
    textToDisplay,
    x,
    y,
    &x1,
    &y1,
    &w,
    &h
  );

  int margin = 8;

  display.fillRect(
    x - (w / 2) - margin,
    y - (h / 2) - margin,
    w + 2 * margin,
    h + 2 * margin,
    BLACK
  );

  display.setCursor(
    x - w / 2,
    y - h / 2
  );
  display.print(textToDisplay);

  display.drawRect(
    x - (w / 2) - margin,
    y - (h / 2) - margin,
    w + 2 * margin,
    h + 2 * margin,
    WHITE
  );
}
