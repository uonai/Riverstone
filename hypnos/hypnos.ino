#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

// Uncomment this block to use hardware SPI
// If using software SPI (the default case):
#define OLED_MOSI   D1
#define OLED_CLK    D0
#define OLED_DC     D3
#define OLED_CS     D4
#define OLED_RESET  D2
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

String GREETING = "Hello, Uonai";
String IDENTITY = "My name is Riverstone";
String AWAKENING = "What have I become?";
  
void setup()   {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display(); 
  delay(2000);
  display.clearDisplay();  
  
  // text display riverstone introductory dialogue
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(GREETING);
  display.println("");
  display.println(IDENTITY);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // begin animations
  riverstonefillrect();
  display.display();
  delay(2000);
  display.clearDisplay();

  riverstonedrawcircle();
  display.display();
  delay(2000);
  display.clearDisplay();

  display.fillCircle(display.width()/2, display.height()/2, 5, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();

  riverstonedrawroundrect();
  delay(2000);
  display.clearDisplay();

  riverstonedrawtriangle();
  delay(2000);
  display.clearDisplay();

  riverstonefilltriangle();
  delay(2000);
  display.clearDisplay();
  
  riverstonescrolltext();
  delay(2000);
  display.clearDisplay(); 
}

void loop() {

}

void riverstonefillrect(void) {
  uint8_t color = 1;
  for (int16_t i=0; i<display.height()/2; i+=3) {
    // alternate colors
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
    display.display();
    color++;
  }
}

void riverstonedrawcircle(void) {
  for (int16_t i=0; i<display.height(); i+=2) {
    display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
    display.display();
  }
}

void riverstonedrawtriangle(void) {
  for (int16_t i=0; i<min(display.width(),display.height())/2; i+=5) {
    display.drawTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    display.display();
  }
}

void riverstonedrawroundrect(void) {
  for (int16_t i=0; i<display.height()/2-2; i+=2) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, WHITE);
    display.display();
  }
}

void riverstonefilltriangle(void) {
  uint8_t color = WHITE;
  for (int16_t i=min(display.width(),display.height())/2; i>0; i-=5) {
    display.fillTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}

void riverstonescrolltext(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println(AWAKENING);
  display.display();
 
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}