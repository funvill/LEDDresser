// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up four NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.

#include "FastLED.h"

#define NUM_STRIPS          6
#define NUM_LEDS_PER_STRIP  30
#define NUM_TOTAL_LEDS      NUM_STRIPS *NUM_LEDS_PER_STRIP

#define TIMER_STEP          100

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

unsigned char hue = 0 ; 
void loop() {  

/*
  // Set everthing to black. 
  for(int x2 = 0; x2 < NUM_STRIPS; x2++) {
    for(int y2 = 0; y2 < NUM_LEDS_PER_STRIP; y2++) {
      leds[x2][y2] = CHSV(0, 0, 0);
    }
  }
  FastLED.show();
  delay(50);
*/
  
  
  // This outer loop will go over each strip, one at a time
  for(int x = 0; x < NUM_STRIPS; x++) {
    // This inner loop will go over each led in the current strip, one at a time
    for(int y = 0; y < NUM_LEDS_PER_STRIP; y++) {
      leds[x][y] = CHSV(hue, 255, 255);
      hue++; 
      FastLED.show();

  /*
      // cycle the remainder LEDS 
      int y2 = y+1;
      for(int x2 = x; x2 < NUM_STRIPS; x2++) {
        for(; y2 < NUM_LEDS_PER_STRIP; y2+=2) {
          leds[x2][y2] = CHSV(hue, 0, 255); // Set to white 
          FastLED.show();
          leds[x2][y2] = CHSV(hue, 0, 0); // Set to black 
        }
        y2=0;
      }
      */
    }

    /*
    // Flash the remaining panels. 
    if( x < NUM_STRIPS-1 ) {
      // Flash white 
      for(int x2 = x+1; x2 < NUM_STRIPS; x2++) {
        for(int y2 = 0; y2 < NUM_LEDS_PER_STRIP; y2++) {
          leds[x2][y2] = CHSV(hue, 0, 255);
        }
      }
      FastLED.show();
      delay(50);
      
      // Set black 
      for(int x2 = x+1; x2 < NUM_STRIPS; x2++) {
        for(int y2 = 0; y2 < NUM_LEDS_PER_STRIP; y2++) {
          leds[x2][y2] = CHSV(hue, 0, 0);
        }
      }
      FastLED.show();
      delay(50);
    }
    */
  }

  // delay(1000*3);
  return ; 
}
