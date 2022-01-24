const int LEFT_BUTTON_PIN = 32;
const int MIDDLE_BUTTON_PIN = 33;
const int RIGHT_BUTTON_PIN = 25;

ButtonsStatus buttonsStatus;

void setupButtons() {
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(MIDDLE_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);
}

void loopButtons() {
  buttonsStatus.left = digitalRead(LEFT_BUTTON_PIN);
  buttonsStatus.middle = digitalRead(MIDDLE_BUTTON_PIN);
  buttonsStatus.right = digitalRead(RIGHT_BUTTON_PIN);

  if(buttonsStatus.left == false) {
    buttonsStatus.leftAlreadyTreated = false;
  }
  
  if(buttonsStatus.middle == false) {
    buttonsStatus.middleAlreadyTreated = false;
  }
  
  if(buttonsStatus.right == false) {
    buttonsStatus.rightAlreadyTreated = false;
  }
}
