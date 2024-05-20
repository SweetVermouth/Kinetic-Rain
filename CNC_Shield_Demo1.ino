const int StepY = 2;
const int DirY = 5;

void setup() {
  pinMode(StepY, OUTPUT);
  pinMode(DirY, OUTPUT);
}

void loop() {
   //3200 steps itu sama dengan 3cm//
  const float frequency = 1; 
  const float amplitude = 28; //jarak perputaran contoh 7 itu sama dengan 7 putaran
  const float kecepatan = 600;
  //////////////////////////////////////////////////////////////////
  const int steps = amplitude * 3200 / 4;
  int decreasingDelay = map(300, 0, steps, 300, 0);
  const int frequency1 = kecepatan + 0.5 * steps * sin(2 * PI * frequency) + decreasingDelay;
  //////////////////////////////////////////////////////////////////
  digitalWrite(DirY, HIGH);
  for (int x = 0; x < steps; x++) {
    digitalWrite(StepY, LOW);
    delayMicroseconds(frequency1); // Reverse the direction of modulation
    digitalWrite(StepY, HIGH);
    delayMicroseconds(0);
  }
  digitalWrite(DirY, LOW);
  for (int x = 0; x < steps; x++) {
    digitalWrite(StepY, LOW);
    delayMicroseconds(frequency1); // Reverse the direction of modulation
    digitalWrite(StepY, HIGH);
    delayMicroseconds(0);
  }
  delay(0);
}
