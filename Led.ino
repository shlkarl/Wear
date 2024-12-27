#include "LED.h"

LED::LED(){
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
}

void LED::light(int c){

if(c == 0){
    for(int i=0; i<50; i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(255,   0,   0));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(50);
  }
}

if(c == 1){
    for(int i=0; i<50; i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(0,   255,   0));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(50);
  }
}

if(c == 2){
    for(int i=0; i<50; i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(0,   0,   255));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(50);
  }
}
if(c == 3){
        for(int i=0; i<50; i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(0,   0,   0));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(50);                           //  Pause for a moment
  }
}
}
  
   /* colorWipe(strip.Color(255,   0,   0), 50); // Red
  colorWipe(strip.Color(  0, 255,   0), 50); // Green
  colorWipe(strip.Color(  0,   0, 255), 50); // Blue

  // Do a theater marquee effect in various colors...
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
  theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness

  rainbow(10);             // Flowing rainbow cycle along the whole strip
  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant*/
  



/*void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    strip.rainbow(firstPixelHue);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear(); 
      for(int c=b; c<strip.numPixels(); c += 3) {
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}*/
