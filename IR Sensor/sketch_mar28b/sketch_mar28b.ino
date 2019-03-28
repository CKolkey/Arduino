#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 3

CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  float sensor = analogRead(A0);
  Serial.println(sensor);

  if (sensor < 80) {
    FastLED.setBrightness(10);
  } else {
    FastLED.setBrightness(sensor / 10);
  }
  

  letThereBeLight();
  

}

void letThereBeLight() {
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(127, 0, 0);
    FastLED.show();
    delay(1);
    
  }
  
}
