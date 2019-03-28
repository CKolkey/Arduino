#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 3
#define BRIGHTNESS 25
#define BUTTON_PIN 2

CRGB leds[NUM_LEDS];

boolean buttonPressed = false;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

}


void loop() {
  buttonPressed = digitalRead(BUTTON_PIN);
  Serial.println(buttonPressed);

  WallStart();



}

void WallStart() {

  for (int n = 0; n < 16; n ++) {
    leds[n] = CRGB(255,255,255);
    delay(10);
    leds[n] = CRGB(0,0,0);
  }

  FastLED.show();
  
}
