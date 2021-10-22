#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

int buzzerPin = 4; 
int code = 0;//부연이 여기에 페트병 고유번호 연동 ㄱㄱ
int red = 9; 
int green = 10;
int blue = 11;
int pick=0;//부연이 여기에 자기껀지 아닌지 구분해주는 함수 넣어 자기꺼면 0넣고 자기꺼아니면 1 넣어
int bacordcorrect=0;//부연이 여기에 바코드가 인식 되었는지 안되었는지 알려야함 바코드 인식 됐으면 0 안되었으면 1을 넣어야함

SoftwareSerial BTSerial(2,3); // RX, TX
LiquidCrystal_I2C lcd(0x27, 16, 2);

void project(int code,int pick,int bacordcorrect)
{
   if(pick == 0){
    if(bacordcorrect==0){
      lcd.setCursor(0,0);
      lcd.print(" yours p:+100");
      lcd.setCursor(1,1);
      lcd.print("code: " + String(code));
      tone(buzzerPin, 1000);
      delay(90);
      noTone(buzzerPin);
      digitalWrite(green,HIGH);
      delay(1000);
      digitalWrite(green,LOW);
      delay(1000);
  }
  
 }
else{
  if(bacordcorrect==0){
    lcd.setCursor(0,0);
    lcd.print(" not yours p:+200");
    lcd.setCursor(1,1);
    lcd.print("code: " + String(code));
    tone(buzzerPin, 1000);
    delay(90);
    noTone(buzzerPin);
  
     digitalWrite(red,HIGH);
    delay(1000);
    digitalWrite(red,LOW);
    delay(1000);
  }
 }
  
  }
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("ATcommand"); 
}

void loop() {
  int a=0;
  int b=0;
  int c=0;
  /*a = ???
  b = ???
  c = ???   여기에 데이터 관련 변수들 쳐줘*/ 
  //project(a,b,c);
  if (BTSerial.available()) {
    char btread = BTSerial.read();
    String content = "";
    content.concat(character);
    
    if (btread == "buzz") {
      project(a, b, c);
    }
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }

 
 }
