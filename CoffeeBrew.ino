#include <LiquidCrystal.h>

// LCD Pinout
#define RS    12
#define EN    11
#define D4    5
#define D5    4
#define D6    3
#define D7    2

// The LCD instance
LiquidCrystal LCD(RS, EN, D4, D5, D6, D7);

void setup() {
  LCD.begin(16, 2);
  LCD.clear();
  LCD.setCursor(1, 0);
  LCD.print("* CoffeeBrew *");
  LCD.setCursor(1, 1);
  LCD.print("Calibrating...");
  
  // Do setup
  // Calibrate valve
  // Calibrate sensor
  InitValve();
  
  LCD.clear();
}

void loop() {
  
}
