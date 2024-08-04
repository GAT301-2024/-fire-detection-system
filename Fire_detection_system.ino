// Pin configuration
const int FLAME_SENSOR_PIN = 2;
const int BUZZER_PIN = 3;
const int LED_PIN = 4;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set pin modes
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read the flame sensor
  int flameSensorValue = digitalRead(FLAME_SENSOR_PIN);

  if (flameSensorValue == LOW) {
    // Fire detected
    Serial.println("Fire detected!");
    soundAlarm();
    flashLight();
  } else {
    // No fire detected
    Serial.println("No fire detected.");
  }

  // Wait for a short period before checking againgv
  delay(1000);
}

void soundAlarm() {
  // Turn the buzzer on and off to create an alarm sound
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
}

void flashLight() {
  // Turn the LED on and off to create a flashing light effect
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
