#include "Gsender.h"
#include<ESP8266WiFi.h>
/*IPAddress ip(192,168,43,150);
IPAddress gateway(192,168,43,1);
IPAddress subnet(255,255,255,0);*/
const char* ssid = "Redmi";
const char* password = "mona1998";
int value =1;
WiFiClient client;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   delay(10);

     //connect to wifi network
     pinMode(D0,INPUT);
     pinMode(D1,OUTPUT);
     Serial.println("\n");
     Serial.print("connecting to");
     Serial.println(ssid);

     //prevent reconnection issue (taking too long to connect
     //pinMode(D4,OUTPUT);
     //digitalWrite(D4,value);
     WiFi.mode(WIFI_OFF);
     delay(1000);

     //this line hides the viewing of ESP as wifi hotspot

     WiFi.mode(WIFI_STA);    
     //WiFi.config(ip,gateway,subnet);   //for getting or assign a fixed IP
     WiFi.begin(ssid,password);

     while(WiFi.status() !=WL_CONNECTED)
     {
      delay(500);
     }
   Serial.println(".");
   Serial.println("/n");
   Serial.println("WiFi connected");
  // Serial.print("localIP");      //for getting the IP address
   //  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  Gsender *gsender = Gsender::Instance();
  String subject = "TempDetector";

  //mailing
  if(digitalRead(D0)==1){
    Serial.println("Motion sensed");
  if(gsender->Subject(subject)->Send("ashavari.c98@gmail.com","ALERT!! YOUR HOUSE HAS BEEN BREACHED"))
  {
    Serial.println("Message sent");
  }
  else{
    Serial.print("Error sending message:");
    Serial.println(gsender->getError());
  }
  tone(D1,492);
  delay(800);
  tone(D1,330);
  delay(800);
  tone(D1,294);
  delay(800);
  tone(D1,262);
  }
  delay(2);
}
