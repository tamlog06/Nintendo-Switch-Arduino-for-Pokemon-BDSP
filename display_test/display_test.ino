/*
  This is an Example for the FaBo LCD mini I2C Brick.

 LiquidCrystal Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 compatible library 2 Mar 2016
 by Hideki Yamauchi

 This example code is in the public domain.

 http://fabo.io/213.html
*/

// include the library code:
#include <Wire.h>
#include <FaBoLCDmini_AQM0802A.h>
#include <math.h>
#include <EEPROM.h>

// initialize the library
FaBoLCDmini_AQM0802A lcd;
const int DIN_PIN = 7;
int count;
int value;

void setup() {
  pinMode( DIN_PIN, INPUT_PULLUP );
  // set up the LCD:

  lcd.begin();  
  delay(1000);
  // Print a message to the LCD.
  lcd.print("hello!");
  delay(1000);
  lcd.clear();
  EEPROM.put(0x000, 214);
//  EEPROM.get(0x000, count);

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
//  lcd.setCursor(0, 1);
//  // print the number of seconds since reset:
//  lcd.print(millis() / 1000);
//  delay(100);

  if (digitalRead(DIN_PIN) == 0) {
    EEPROM.put(0x000, count+1);
    EEPROM.get(0x000, count);
    lcd.setCursor(0, 0);
    lcd.print(count);
    lcd.setCursor(0, 1);
    lcd.print((100.0 - (pow(4095.0/4096.0, count))*100.0));
    lcd.setCursor(5, 1);
    lcd.print("%");
//    delay(10);
   }
//   delay(100);
}
