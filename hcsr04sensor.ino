#define trigPin 9  // Trigger pin connected to Arduino digital pin 2
#define echoPin 10   // Echo pin connected to Arduino digital pin 3
#define buzzerPin 6// Buzzer pin connected to Arduino digital pin 7

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Trigger an ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the echo to return
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  float distance_cm = duration * 0.0343 / 2;

  // Check if an object is within a certain range (adjust the range as needed)
  if (distance_cm < 10) {
    // Object detected within 10 cm, activate the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(400); // Buzzer on for 0.5 seconds
    digitalWrite(buzzerPin, LOW);
  }

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(1000); // Wait for a moment before taking the next reading
}