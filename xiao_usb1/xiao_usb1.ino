/*
 * Sample program demonstrating TinyUSB_Mouse_and_Keyboard.h module which
 * auto selects between standard Arduino Mouse.h API and TinyUSB mouse API.
 * This program tests the keyboard portion alone.
 */

//Include this module whether using Arduino stack or TinyUSB stack
// https://github.com/cyborg5/TinyUSB_Mouse_and_Keyboards
#include <TinyUSB_Mouse_and_Keyboard.h>

// Launchpad sc > F5
void setup() {
  Keyboard.begin();   //Unlike Arduino Keyboard.h, you must use begin.
  Serial.begin(115200);
  while (! Serial)delay (1);
  Serial.println("USB keyboard test");

  //find terminal
  Keyboard.write(KEY_F5);
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.write('f');
  Keyboard.releaseAll();
  delay(100);
  // 英字モードに変更。CTL＋SHIFT+;
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(';');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("terminal");
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);
  // New terminal windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('n');
  Keyboard.releaseAll();
  //open https://junkhack.gpl.jp/
  Keyboard.print("open https://junkhack.gpl.jp/");
  Keyboard.press(KEY_RETURN);
  
  Keyboard.releaseAll();         //release the control key
  Serial.println("USB keyboard test completed");
};
void loop() {
}

/*
 * Click below before uploading and it will type characters in this comment
 * 
 * 
 *  
 *  
 *  
 *  
 *  
 *  
 */
