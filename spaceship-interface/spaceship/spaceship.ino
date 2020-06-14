/* tobias leong
  starship interface
*/

int switchState = 0;
int delay_duration;

void print_delay(int delay_duration) {
    Serial.print("Delay duration: ");
    Serial.print(delay_duration);
    Serial.println(" ms");
}

// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, INPUT);
    pinMode(3, OUTPUT); // GREEN LED
    pinMode(4, OUTPUT); // RED LED
    pinMode(5, OUTPUT); // RED LED
    Serial.begin(9600); // init Serial monitor on baud 9600
}

// the loop function runs over and over again forever
void loop() {
    switchState = digitalRead(2);
    delay_duration = random(100, 1000);
    print_delay(delay_duration);
  
    if (switchState == LOW) {
      // button is not pressed
      // can use switchState == 0 too
      Serial.println("Button is not pressed.");
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
  
      // alternate blink even when button is not pressed
      delay(delay_duration);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(delay_duration);
    } else {
      // button is pressed
      Serial.println("Button is pressed;");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
  
      // toggle LEDs
      delay(100);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(100);
    }
}
