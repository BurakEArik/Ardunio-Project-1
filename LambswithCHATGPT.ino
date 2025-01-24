const int red = 3;
const int yellow = 9;
const int green = 5;
int now;
int past = 0;
#define button 2
#define button2 6

void setup() {
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  if (digitalRead(button) == 0) {
    repeat(green);
    repeat(yellow);
    repeat(red);
  }
  if (digitalRead(button2) == 1) {
    repeat(red);
    repeat(yellow);
    repeat(green);
  }
}



void repeat(int x) {
  fadeLEDUP(x);
  delay(500);
  fadeLEDDOWN(x);
  delay(100);
}

void fadeLEDUP(int pin) {
  for (int brightness = 0; brightness <= 255; brightness += 15) {
    analogWrite(pin, brightness);  // Parlaklığı artır
    delay(20);
  }
}

void fadeLEDDOWN(int pin) {
  for (int brightness = 255; brightness >= 0; brightness -= 15) {
    analogWrite(pin, brightness);  // Parlaklığı azalt
    delay(20);
  }
}
