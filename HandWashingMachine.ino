
const int sensor = 7;
const int Relay = 10;
const int trigss = 5;
const int echoss = 4;
const int ledWhite = 8;
const int ledRed = 12;
const int Relay1 = 9;
int resis;
int val;
unsigned long duration;
unsigned long distance;
void setup()
{
  pinMode(sensor, INPUT);
  pinMode(Relay, OUTPUT);
  pinMode(Relay1,OUTPUT);
  pinMode(trigss, OUTPUT);
  pinMode(echoss, INPUT);
  Serial.begin(9600);
}



void loop()
{
    resis = analogRead(A0);
    int real_resis = map(resis,0,1023,0,255);

    if(real_resis < 100) {
      Serial.print("v");
      val = digitalRead(sensor);
      Serial.println(val);
      if (val == 1) {
      digitalWrite(Relay,HIGH);
    } 
    else {
      digitalWrite(Relay,LOW);
      delay(1000);
    }
    delay(1000);

    digitalWrite(trigss,LOW);   // tắt chân trig
    delayMicroseconds(10);
    digitalWrite(trigss,HIGH);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trigss,LOW);   // tắt chân trig
    duration = pulseIn(echoss,HIGH);
    distance = int(duration/2/29.412);
    Serial.print("d");
    Serial.println(distance);
    Serial.print("r");
    Serial.println(real_resis);
    if (distance > 1 && distance < 20) {
      digitalWrite(Relay1,LOW);
      delay(1000);
    } 
    else {
      digitalWrite(Relay1,HIGH);
    }
     delay(1000);
    }
  else {
    if (Serial.available())
    {
     char var = Serial.read();
  
      if (var == 'o')
        {
          digitalWrite(Relay, LOW);
        }
      else if (var == 'f')
        {
          digitalWrite(Relay, HIGH);
        }

  
      if(var == 'a') {
        digitalWrite(Relay1, LOW);
      }
      else if(var == 'b') {
        digitalWrite(Relay1,HIGH);
      }
    Serial.print("v");
    val = digitalRead(sensor);
    Serial.println(val);
    digitalWrite(trigss,LOW);   // tắt chân trig
    delayMicroseconds(10);
    digitalWrite(trigss,HIGH);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trigss,LOW);   // tắt chân trig
    duration = pulseIn(echoss,HIGH);
    distance = int(duration/2/29.412);
    Serial.print("d");
    Serial.println(distance);
    Serial.print("r");
    Serial.println(real_resis);
  }

}

 }

