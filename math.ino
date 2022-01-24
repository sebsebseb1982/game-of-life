
void setupMath() {
  randomSeed(analogRead(0));
}

bool randomBoolean() {
  if (random(10) < 5) {
    return true;
  } else {
    return false;
  }
}
