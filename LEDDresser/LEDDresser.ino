// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up four NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.

#include "FastLED.h"

#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 30
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];


// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  FastLED.addLeds<NEOPIXEL, 2>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 3>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 6>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 7>(leds[5], NUM_LEDS_PER_STRIP);
}

void loop() {
  /*
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[0][i] = CRGB::Red;
  }
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[1][i] = CRGB::Green;
  } 
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[2][i] = CRGB::Blue;
  }
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[3][i] = CRGB::Yellow;
  } 
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[4][i] = CRGB::Aqua;
  }
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[5][i] = CRGB::BlueViolet;
  }

    FastLED.show();

return ; 
  */
  // This outer loop will go over each strip, one at a time
  for(int x = 0; x < NUM_STRIPS; x++) {
    // This inner loop will go over each led in the current strip, one at a time
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB::Red;
      FastLED.show();
      delay(100);
    }
  }

  // Set all to black 
  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB::Black;
    }
  }
  FastLED.show();
  delay(1000);
}
