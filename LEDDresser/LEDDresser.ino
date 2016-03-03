// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up four NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.

#include "FastLED.h"

#define NUM_STRIPS          6
#define NUM_LEDS_PER_STRIP  30
#define NUM_TOTAL_LEDS      NUM_STRIPS *NUM_LEDS_PER_STRIP

#define TIMER_STEP          20

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

 
unsigned char gHue = 0 ;
void loop() 
{ 
  unsigned char hue = gHue ;
  
  // This outer loop will go over each strip, one at a time
  for(int x = 0; x < NUM_STRIPS; x++) {
    if( x % 2 == 0 ) { 
      for(int y = 0; y < NUM_LEDS_PER_STRIP; y++) {
        leds[x][y] = CHSV(hue, 255, 255);
        hue++; 
        // FastLED.show();      
      }
    } else {
      for(int y = NUM_LEDS_PER_STRIP; y > 0 ; y--) {
        leds[x][y] = CHSV(hue, 255, 255);
        hue++;
        // FastLED.show();
      }
    }    
  }
  delay(TIMER_STEP);
  gHue += 1 ;
  FastLED.show();
  return ; 
}
