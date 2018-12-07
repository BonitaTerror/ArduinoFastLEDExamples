#include <FastLED.h>

#define NUM_LEDS 100
#define LED_PIN 6
#define TIME_DELAY 4 * 1000

struct color {
  int r;
  int g;
  int b;
};

struct color Color;

float fade_scale = 1.2;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

}

void loop() {
  mix_blue_yellow(0);
  delay(TIME_DELAY);
  mix_blue_yellow(1);
  delay(TIME_DELAY);

}

void mix_blue_yellow(int mode) {
  for (int i=0; i<NUM_LEDS; i++) {
    if (i%2 == mode) {
      Color.r = 233;
      Color.g = 221;
      Color.b = 56;
      leds[i] = CRGB(Color.r, Color.g, Color.b);
    } else {
      Color.r = 80;
      Color.g = 230;
      Color.b = 230;
      leds[i] = CRGB(Color.r, Color.g, Color.b);
    }
    FastLED.show();
  }
}
