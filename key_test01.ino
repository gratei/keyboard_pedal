#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  pinMode(2, INPUT_PULLUP); //スイッチ入力（反対側はGNDへ接続）
  pinMode(9, OUTPUT); //動作確認用のLED（半角入力時に点灯）
  Serial.begin(9600);

}

bool anow= LOW;
bool a = LOW;

void loop() {
  if(digitalRead(2) == HIGH && anow == LOW){ //ペダルが踏み込まれている時
    a = !a;
    anow = HIGH;
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(0x27);
    delay(90);
    Keyboard.release(KEY_RIGHT_CTRL);
    Keyboard.release(KEY_RIGHT_SHIFT);
    Keyboard.release(0x27);
    digitalWrite(9,HIGH);
    
  }
  while(digitalRead(2) == HIGH && anow == HIGH){
  }

  if(digitalRead(2) == LOW && anow == HIGH){ //ペダルが踏み込まれていない時
    anow = LOW;
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press('j');
    delay(90);
    Keyboard.release(KEY_RIGHT_CTRL);
    Keyboard.release(KEY_RIGHT_SHIFT);
    Keyboard.release('j');
    digitalWrite(9,LOW);
  }
  while(digitalRead(2)==LOW && anow == LOW){
  }


}
