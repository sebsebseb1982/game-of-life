const int LIGHT_SENSOR_PIN = 26;

float getLightSensorValue() {
  return analogRead(LIGHT_SENSOR_PIN) / 4095.0;
}
