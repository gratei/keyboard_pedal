#include "Keyboard.h"

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  pinMode(2, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

bool anow= LOW;
bool a = LOW;

void loop() {
  // 導通（離している状態）でL，切断でH:
  if(digitalRead(2) == HIGH && anow == LOW){
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

  if(digitalRead(2) == LOW && anow == HIGH){
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
