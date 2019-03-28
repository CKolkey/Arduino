#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 3
#define BRIGHTNESS 25

CRGB leds[NUM_LEDS];


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);

}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(127, 0, 0);
    FastLED.show();
    delay(100);
  }
  for (int i = NUM_LEDS; i <= 0; i--) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(100);
  }

}
