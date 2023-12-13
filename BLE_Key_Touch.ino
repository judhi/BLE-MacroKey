/*  BLE Custom Macro Key Touch
    by Judhi Prasetyo 2023
    based on T-vK/ESP-BLE-Keyboard
    (https://github.com/T-vK/ESP32-BLE-Keyboard)

    This code is available on
    https://github.com/judhi/BLE-MacroKey

    Use this virtual drum:
    https://www.virtualdrumming.com/drums/online-virtual-games/online-virtual-games-drums.html
*/

#define TouchPin1 T2
#define TouchPin2 T4
#define TouchPin3 T6

const int UPPER_THRESHOLD = 40;
const int LOWER_THRESHOLD = 10;
int t1, t2, t3;

#include <BleKeyboard.h>

/* change the name below */
BleKeyboard bleKeyboard("Judhi BLE-Drum", "Judhi", 100);

void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  bleKeyboard.begin();
  pinMode(2, OUTPUT);
  delay(500);
  Serial.println("BLE Touch Macro ready!");
}

void loop() {
  delay(50);
  t1 = touchRead(TouchPin1);
  t2 = touchRead(TouchPin2);
  t3 = touchRead(TouchPin3);

  if (t1 > LOWER_THRESHOLD && t1 < UPPER_THRESHOLD) {
    Serial.print(t1);
    Serial.println(" Touched 1");
    bleKeyboard.print("x");
    delay(200);
  }

  if (t2 > LOWER_THRESHOLD && t2 < UPPER_THRESHOLD) {
    Serial.print(t2);
    Serial.println(" Touched 2");
    bleKeyboard.print("c");
    delay(200);
  }

  if (t3 > LOWER_THRESHOLD && t3 < UPPER_THRESHOLD) {
    Serial.print(t3);
    Serial.println(" Touched 3");
    bleKeyboard.print("b");
    delay(200);
  }
}

/*
   # Sending single keystroke examples:
     bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
     bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
     bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
     bleKeyboard.write(KEY_RETURN);

   # Sending text example:
     bleKeyboard.print("Hello world");

   # Sending CTRL-C example (all 4 lines needed):
     bleKeyboard.press(KEY_LEFT_CTRL);
     bleKeyboard.press('c');
     delay(100);
     bleKeyboard.releaseAll();

   # for list of key modifiers please visit:
     https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
*/
