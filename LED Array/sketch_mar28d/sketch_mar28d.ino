#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN 3
#define BRIGHTNESS 20
#define SENSOR_FLOOR 70
#define SENSOR_CEIL 600

CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  float sensor = analogRead(A0);
  Serial.println(sensor);

//    randomNoise();
  bouncePositive();
//  RainbowGrad();


}

void letThereBeLight() {
  float sensor = analogRead(A0);
  int BRIGHT = map(sensor, 30, 600, 10, 100);
  FastLED.setBrightness(BRIGHT);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(127, 0, 0);
    FastLED.show();
  }
  
}
void bouncePositive() {
  float sensor = analogRead(A0);
  int led_count = map(sensor, SENSOR_FLOOR, SENSOR_CEIL, 0, 15);
  int color = map(sensor, SENSOR_FLOOR, SENSOR_CEIL, 0, 220);
  
  leds[led_count] = CHSV(color, 255, 255);
  FastLED.show();
  leds[led_count] = CRGB(0, 0, 0);
}

void RainbowGrad() {
    float sensor = analogRead(A0);
    int color = map(sensor, SENSOR_FLOOR, SENSOR_CEIL, 0, 255);
    int led_off = map(sensor, SENSOR_FLOOR, SENSOR_CEIL, 0, 15);
    
    leds[0] = CHSV(color, 255, 255);
    leds[1] = CHSV(color, 255, 255);
    leds[2] = CHSV(color, 255, 255);
    leds[3] = CHSV(color, 255, 255);
    
    leds[4] = CHSV(color + 10, 255, 255);
    leds[5] = CHSV(color + 10, 255, 255);
    leds[6] = CHSV(color + 10, 255, 255);
    leds[7] = CHSV(color + 10, 255, 255);
        
    leds[8] = CHSV(color + 20, 255, 255);
    leds[9] = CHSV(color + 20, 255, 255);
    leds[10] = CHSV(color + 20, 255, 255);
    leds[11] = CHSV(color + 20, 255, 255);
        
    leds[12] = CHSV(color + 30, 255, 255);
    leds[13] = CHSV(color + 30, 255, 255);
    leds[14] = CHSV(color + 30, 255, 255);
    leds[15] = CHSV(color + 30, 255, 255);

    FastLED.show();
 
}
