#define LED1 3
#define LED2 5
#define BUZZER 6
#define trigPin 9
#define echoPin 10
#define SOUND_VELOCITY 0.034

long duration;
float value;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(LED1, LOW); // setting the output to low, i.e, turning them off
  digitalWrite(LED2, LOW);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  value = duration * SOUND_VELOCITY/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(value);
  if (value <= 7 && value > 4.5){
    digitalWrite(LED1, HIGH);
  }
  if (value <= 4.5 && value > 3.5){
    digitalWrite(LED2, HIGH);
  }
  if (value <= 3.5){
    digitalWrite(BUZZER, HIGH);
  }
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(BUZZER, LOW);

  delay(1000);
}
