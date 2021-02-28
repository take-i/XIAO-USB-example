/*
  XIAO USB Keyboard.example.
  https://junkhack.gpl.jp/2021/03/01/make-mac-sskey-xiao/
*/

// https://github.com/cyborg5/TinyUSB_Mouse_and_Keyboard
//#include <TinyUSB_Mouse_and_Keyboard.h>
#include "TinyUSB_Mouse_and_Keyboard.h"

uint8_t pins[] = { A7 , A8 , A9 , A10 };
uint8_t Key0; //A7
uint8_t Key1; //A8
uint8_t Key2; //A9
uint8_t Key3; //A10
// 残り７Pin

void setup() {
  Keyboard.begin();
  // led pin
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  //
  pinMode(pins[0], INPUT_PULLUP);
  pinMode(pins[1], INPUT_PULLUP);
  pinMode(pins[2], INPUT_PULLUP);
  pinMode(pins[3], INPUT_PULLUP);
}

void loop() {
  Key0 = digitalRead(pins[0]);
  Key1 = digitalRead(pins[1]);
  Key2 = digitalRead(pins[2]);
  Key3 = digitalRead(pins[3]);

  if (Key0 == LOW ) {       // XIAOでは、LOW = On
      Key0_act();
  }
  if (Key1 == LOW ) {
      skitch_ss();
  }
  if (Key2 == LOW ) {
      skitch_pict_copy();
  }
  if (Key3 == LOW ) {
      Key3_act();
  }
}

void Key0_act() {
  // esc
  Keyboard.write(KEY_ESC);
  
  digitalWrite(LED_BUILTIN, LOW);
  KeyRelease();
}

void skitch_pict_copy() {
  //find skitch
  Keyboard.write(KEY_F5);
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.write('f');
  Keyboard.releaseAll();
  delay(100);
  // 英字モードに変更する必要ある。CTL＋SHIFT+;
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(';');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("skitch");
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);
  // skitch pict copy
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('c');
  Keyboard.releaseAll();
  delay(100);
  // ひらがなモードに変更。CTL＋SHIFT+j
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('j');
  Keyboard.releaseAll();
  
  digitalWrite(LED_BUILTIN, LOW);// XIAOでは、LOW = On
  KeyRelease();
}

void skitch_ss() {
  // skitch
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('5');
  
  digitalWrite(LED_BUILTIN, LOW);
  KeyRelease();
}

void Key3_act() {
  //find terminal
  Keyboard.write(KEY_F5);
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.write('f');
  Keyboard.releaseAll();
  delay(100);
  // 英字モードに変更する必要ある。CTL＋SHIFT+;
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
  //open URL
  Keyboard.print("open https://www.canva.com/");
  Keyboard.press(KEY_RETURN);
  
  digitalWrite(LED_BUILTIN, LOW);
  KeyRelease();
}

void KeyRelease() {
  Keyboard.releaseAll();
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);// XIAOでは、HIGH = Off
}
