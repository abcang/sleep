int val = 0;
int iPin = A0;
int oPin = 13;
boolean flag = true;
uint8_t buf[2] = { 0 };     /* Report buffer 8Byte */

void setup()
{
  pinMode(oPin, OUTPUT);
  Serial.begin(9600);
  delay(200);
}

void loop()
{
  val = analogRead(iPin);
  if(val<600){
    flag = false;
    digitalWrite(oPin, LOW);
  }else{
    if (flag == false) {
      digitalWrite(oPin, HIGH);
      sleep();
      flag = true;
      delay(5000);
      digitalWrite(oPin, LOW);
    }
  }
  delay(1000);
}

void sleep()
{
  buf[0] = 2;
  buf[1] = 1;
  Serial.write(buf,2);

  delay(200);

  // これを送らないとブルースクリーンになる
  buf[0] = 0;
  buf[1] = 0;
  Serial.write(buf,2);
}

