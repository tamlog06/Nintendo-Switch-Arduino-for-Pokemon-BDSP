#include <SwitchControlLibrary.h>
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
  // put your setup code here, to run once:
  SwitchControlLibrary(); // 初期化
  pinMode( DIN_PIN, INPUT_PULLUP );

  lcd.begin();  
  delay(1000);
  // Print a message to the LCD.
  lcd.print("hello!");
  delay(1000);
  lcd.clear();

  EEPROM.get(0x000, count);
  lcd.setCursor(0, 0);
  lcd.print(count);
  lcd.setCursor(0, 1);
  lcd.print((100.0 - (pow(4095.0/4096.0, count))*100.0));
  lcd.setCursor(5, 1);
  lcd.print("%");
}

// 0.1s
void pushA(){
   SwitchControlLibrary().pressButton(Button::A); // Aボタンを押す
   SwitchControlLibrary().sendReport(); // Aボタンを押したことを反映
   delay(50); // 50 ms 待機
   SwitchControlLibrary().releaseButton(Button::A); // Aボタンを離す
   SwitchControlLibrary().sendReport(); // Aボタンを離したことを反映
   delay(50); // 50 ms 待機
}

//0.1s
void pushHOME(){
   SwitchControlLibrary().pressButton(Button::HOME);
   SwitchControlLibrary().sendReport();
   delay(50); // 50 ms 待機
   SwitchControlLibrary().releaseButton(Button::HOME);
   SwitchControlLibrary().sendReport();
   delay(50); // 50 ms 待機
}

//0.1s
void pushX(){
   SwitchControlLibrary().pressButton(Button::X);
   SwitchControlLibrary().sendReport();
   delay(50); // 50 ms 待機
   SwitchControlLibrary().releaseButton(Button::X);
   SwitchControlLibrary().sendReport();
   delay(50); // 50 ms 待機
}

void loop() {
  // put your main code here, to run repeatedly:
//   SwitchControlLibrary().pressButton(Button::A); // Aボタンを押す
//   SwitchControlLibrary().sendReport(); // Aボタンを押したことを反映
//   delay(50); // 50 ms 待機
//   SwitchControlLibrary().releaseButton(Button::A); // Aボタンを離す
//   SwitchControlLibrary().sendReport(); // Aボタンを離したことを反映
//   delay(50); // 50 ms 待機

   float time = 0.0;
   lcd.setCursor(7, 0);
   lcd.print("A");
   while (time < 2.5) {
    pushA();
    time += 0.1;
   }
   lcd.setCursor(7, 0);
   lcd.print(0);
   
   delay(20000);
   
   time = 0.0;
   lcd.setCursor(7, 0);
   lcd.print("A");
   while (time < 7) {
    pushA();
    time += 0.1;
   }
   lcd.setCursor(7, 0);
   lcd.print(0);

   delay(8000);

   time = 0.0;
   lcd.setCursor(7, 0);
   lcd.print("A");
   while (time < 2) {
    pushA();
    time += 0.1;
   }
   lcd.setCursor(7, 0);
   lcd.print(0);

   
   while (1) {
    // ボタン待ち
    value = digitalRead(DIN_PIN);
    if (value == 0) {
      EEPROM.put(0x000, count+1);
      EEPROM.get(0x000, count);
      lcd.setCursor(0, 0);
      lcd.print(count);
      lcd.setCursor(0, 1);
      lcd.print((100.0 - (pow(4095.0/4096.0, count))*100.0));
      lcd.setCursor(5, 1);
      lcd.print("%");
      break;
    }
    delay(10);
   }

   lcd.setCursor(7, 0);
   lcd.print("H");
   pushHOME();
   delay(300);
   lcd.setCursor(7, 0);
   lcd.print("X");
   pushX();
   delay(300);
   lcd.setCursor(7, 0);
   lcd.print("A");
   pushA();
   
}
