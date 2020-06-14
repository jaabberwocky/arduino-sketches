const int sensor_pin = A0;
const float baseline_temp = 29.0;

void setup() {
  Serial.begin(9600);
  for (int pin_num = 2; pin_num < 5; pin_num ++) {
    pinMode(pin_num, OUTPUT);
    digitalWrite(pin_num, LOW);
  }
}

void loop() {
  int sensor_val = analogRead(sensor_pin);
  float voltage = (sensor_val / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
  Serial.print("Sensor value: ");
  Serial.print(sensor_val);
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  Serial.print(temperature);
  Serial.println(" ");

  // light up LED lights based on reading
  if (temperature < baseline_temp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baseline_temp + 4 &&
             temperature < baseline_temp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baseline_temp + 6 &&
             temperature < baseline_temp + 8 ) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1); // small delay needed to prevent erratic readings

}
