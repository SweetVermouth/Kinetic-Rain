const int StepY = 2;
const int DirY = 5;

void setup() {
  pinMode(StepY, OUTPUT);
  pinMode(DirY, OUTPUT);
}

void loop() {
  const int steps = 4800;
  const float frequency = 0.1; 
  const float amplitude = 300; 

  digitalWrite(DirY, HIGH);
  for (int x = 0; x < steps; x++) {
    digitalWrite(StepY, LOW);
    delayMicroseconds(700 + amplitude * cos(PI * (steps - x) / steps)); // Reverse the direction of modulation
    digitalWrite(StepY, HIGH);
    delayMicroseconds(0);
  }
  digitalWrite(DirY, LOW);
  for (int x = 0; x < steps; x++) {
    digitalWrite(StepY, LOW);
    delayMicroseconds(700 + amplitude * cos(PI * x / steps));
    digitalWrite(StepY, HIGH);
    delayMicroseconds(0);
  }
  digitalWrite(DirY, LOW);
  for (int x = 0; x < steps; x++) {
    digitalWrite(StepY, LOW);
    delayMicroseconds(700 + amplitude * cos(PI * (steps - x) / steps)); // Reverse the direction of modulation
    digitalWrite(StepY, HIGH);
    delayMicroseconds(0);
  }
  digitalWrite(DirY, HIGH);
  for (int x = 0; x < steps; x++) {
    digitalWrite(StepY, LOW);
    delayMicroseconds(700 + amplitude * cos(PI * x / steps));
    digitalWrite(StepY, HIGH);
    delayMicroseconds(0);
  }
  delay(0);
}
