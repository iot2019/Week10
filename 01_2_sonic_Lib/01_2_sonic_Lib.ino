#include <HCSR04.h>

int trigPin=11;  //아두이노가 전류를 넣어 초음파를 발사하게 하는 핀
int echoPin=12;  //수신부로 입력된 초음파를 받는 핀
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  double distance = distanceSensor.measureDistanceCm();
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
