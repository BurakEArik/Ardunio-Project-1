# Arduino Project 1

## Project Description
This project simulates a traffic light using Arduino. It allows controlling LEDs in different sequences using two buttons.

## Components Used
- 1 x Arduino Uno
- 3 x LEDs (Red, Yellow, Green)
- 3 x 330 Ohm Resistors
- 2 x Push Buttons
- 2 x 10k Ohm Resistors
- Jumper Wires
- Breadboard

## Circuit Diagram
![Circuit Diagram](Terrific%20Bigery-Juttuli.png)

## Code
The project code is as follows:
```cpp
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
```
## How to Use
Assemble the circuit according to the provided diagram.
Upload the code to your Arduino board.
Press the buttons to control the LED sequence.

## About the Buttons
Button 1: Lights LEDs in the order Green → Yellow → Red.
Button 2: Lights LEDs in the reverse order Red → Yellow → Green.                                             
