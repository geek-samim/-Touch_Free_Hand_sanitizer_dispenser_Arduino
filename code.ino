
const int stepPin = 7;
const int dirPin = 6;
const int trigPin = 11;
const int echoPin = 10;
int Step = 5000;
int Delay = 30;
long duration;
int distance;
int state = 0;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}
void loop() {



  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;






  if (distance < 10 ) {
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(1000);
    stepper();
  }

}



void stepper () {


  digitalWrite(dirPin, LOW); // Enables the motor to move in a particular direction

  for (int x = 0; x < Step; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delay);
  }
  delay(50);

  digitalWrite(dirPin, HIGH); //Changes the rotations direction

  for (int x = 0; x < Step; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Delay);
  }
}
