int trigPin=11;  //아두이노가 전류를 넣어 초음파를 발사하게 하는 핀
int echoPin=12;  //수신부로 입력된 초음파를 받는 핀
int piezoPin=7;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  unsigned long distance; //초음파가 발사되어 돌아온 시간  
  //초음파 발생시킴 : 10us 동안 전류를 trigPin에 출력
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);       //초기화
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //돌아온 초음파를 분석하여 거리 계산
  distance = pulseIn(echoPin, HIGH)/2 * 0.034;  
        //왕복시간이므로 반으로 나눈다 : 반환값은 unsigned long
        //cm와 microsecond의 단위를 통일시켜야 함
        //1m = 100cm : 340m --> 34000cm
        //1s = 1,000,000us
        //34000/1000000 --> 0.034cm/us
  //화면 출력
  Serial.print("distance : ");  Serial.print(distance);
  Serial.println(" cm");  delay(500);

  noTone(piezoPin);
  if(distance<10){           //거리가 10cm미만일 경우
    tone(piezoPin, 1000, 300);  //tone(pin, frequency, duration)
  } else if(distance<20){    //거리가 10cm~20cm미만일 경우
    tone(piezoPin, 3000, 200); 
  } else if(distance<30){    //거리가 12cm~30cm미만일 경우
    tone(piezoPin, 5000, 100);
  } else{                    //거리가 30cm이상일 경우
    noTone(piezoPin);
  } 
}
