#include "FastLED.h"

#define NUM_STRIPS          6
#define NUM_LEDS_PER_STRIP  30
#define NUM_TOTAL_LEDS      NUM_STRIPS *NUM_LEDS_PER_STRIP

#define TIMER_STEP          10

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

 for( unsigned char brightness = 80 ; brightness < 255 ; brightness ++ ) {
    for( unsigned char count = 0 ; count < 20 ; count++ ) {
      unsigned char hue = gHue ;
      
      // This outer loop will go over each strip, one at a time
      for(int x = 0; x < NUM_STRIPS; x++) {
        for(int y = 0; y < NUM_LEDS_PER_STRIP; y++) {
          leds[x][y] = CHSV(hue, 255, brightness);
          hue++;    
        }
      }
        
      gHue++ ;
      FastLED.show();
      delay(TIMER_STEP);
    }    
  }
    
  return ; 
}
