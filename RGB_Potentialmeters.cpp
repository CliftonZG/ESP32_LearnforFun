#include <Arduino.h>

#define POTENTIOMETER_LIGHT  35
#define POTENTIOMETER_RED    36
#define POTENTIOMETER_GREEN  39
#define POTENTIOMETER_BLUE   34
#define PIN_BLUE             18
#define PIN_GREEN            19
#define PIN_RED              21

void setup() {
  // put your setup code here, to run once:

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // declare RGB pin to be an output:
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // scales it to brightness (value between 0 and 255)
  int brightValue = analogRead(POTENTIOMETER_LIGHT);
  int brightness = map(brightValue, 0, 4095, 0, 255);

  int redanalogue = analogRead(POTENTIOMETER_RED);
  int redValue = map(redanalogue, 0, 4095, 0, 255);

  int greenanalogue = analogRead(POTENTIOMETER_GREEN);
  int greenValue = map(greenanalogue, 0, 4095, 0, 255);

  int blueanalogue = analogRead(POTENTIOMETER_BLUE);
  int blueValue = map(blueanalogue, 0, 4095, 0, 255);

  float bright = brightness / 255.0;

  if (bright != 0)
  {
    redValue = redValue * bright;
    greenValue = greenValue * bright;
    blueValue = blueValue * bright;
  }
  else
  {
    redValue = 0;
    greenValue = 0;
    blueValue = 0;
  }

  // sets the brightness LED that connects to  pin 3
  analogWrite(PIN_RED,   redValue);
  analogWrite(PIN_GREEN, greenValue);
  analogWrite(PIN_BLUE,  blueValue);

  // print out the value
  Serial.print("Brightness analog value = ");
  Serial.print(brightValue);
  Serial.print(" => brightness = ");
  Serial.println(brightness);
  Serial.print(" => RED = ");
  Serial.println(redValue);
  Serial.print(" => GREEN = ");
  Serial.println(greenValue);
  Serial.print(" => BLUE = ");
  Serial.println(blueValue);
  delay(25);            // wait for 50 milliseconds
}
