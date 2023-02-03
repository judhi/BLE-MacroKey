/*  BLE Custom Macro Key Touch
    by Judhi Prasetyo 2023
    based on T-vK/ESP-BLE-Keyboard
    (https://github.com/T-vK/ESP32-BLE-Keyboard)

    This code is available on
    https://github.com/judhi/BLE-MacroKey
*/

#define TouchPin1 T4
#define TouchPin2 T5
#define TouchPin3 T6
#define TouchPin4 T3

const int UPPER_THRESHOLD = 20;
const int LOWER_THRESHOLD = 5;
int t1, t2, t3, t4;

#include <BleKeyboard.h>

/* change the name below */
BleKeyboard bleKeyboard("Judhi BLE-Touch", "Judhi", 100);

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
  t4 = touchRead(TouchPin4);

  if (t1 > LOWER_THRESHOLD && t1 < UPPER_THRESHOLD) {
    Serial.print(t1);
    Serial.println(" Touched 1");
    bleKeyboard.press(KEY_LEFT_CTRL); // Windows & Linux CTRL key
    // bleKeyboard.press(KEY_LEFT_GUI);  // MacOS & IOS CMD key
    bleKeyboard.press('c');
    delay(100);
    bleKeyboard.releaseAll();
    delay(250);
  }

  if (t2 > LOWER_THRESHOLD && t2 < UPPER_THRESHOLD) {
    Serial.print(t2);
    Serial.println(" Touched 2");
    bleKeyboard.press(KEY_LEFT_CTRL); // Windows & Linux CTRL key
    // bleKeyboard.press(KEY_LEFT_GUI);  // MacOS & IOS CMD key
    bleKeyboard.press('v');
    delay(100);
    bleKeyboard.releaseAll();
    delay(250);
  }

  if (t3 > LOWER_THRESHOLD && t3 < UPPER_THRESHOLD) {
    Serial.print(t3);
    Serial.println(" Touched 3");
    bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    delay(250);
  }

  if (t4 > LOWER_THRESHOLD && t4 < UPPER_THRESHOLD) {
    Serial.print(t4);
    Serial.println(" Touched 4");
    bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    delay(250);
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
