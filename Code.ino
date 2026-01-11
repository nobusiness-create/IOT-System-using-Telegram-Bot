#include <ArduinoHttpClient.h>

#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

#include <TelegramCertificate.h>
#include <UniversalTelegramBot.h>
#include <Wifi.h>
#include <WiFiClientSecure.h>

//Creating Library related variables

const char* ssid ="Place ur wifi network ssid here:";
const char* password="Add your password here";

#define BOTtoken ""
#define CHAT_ID ""

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtokenValue,client);

const int mSensor=12;//Pin number for motion sensor
const int TempSensor=34; //Pin number for temp sensor

bool mDetected=false; //to indicate if motion is detected

void IRAM_ATTAR movementdetection(){
  Serial.println("Motion has been detected!");
  mDetected=true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(mSensor, INPUT_PULLUP);
  
  attachInterrupt(digitalPinInterrupt(mSensor),movementdetection,RISING);
  
  Serial.print("Trying to connect to WiFi:");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFI.begin(ssid,password);
  client.setCACert(TELEGRM_CERTIFICTE_ROOT);

while(WiFi.status()!=WL_CONNECTED){
  serial.print(".");
  delay(300);
}
Serial.println("");
Serial.println("WIFI CONNECTED");
Serial.print("IR Address");
Serial.println(WiFi.localIP());

bot.sendMessage(OUR_CHAT_ID,"Motion n Temperture Bot started Up ");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (mDetected ==true){
   bool result= bot.sendMessage(OUR_CHAT_ID,"Motion has been detetcted:");
   if (result){
    Serial.println("Message succesfully sent!");
   }
   else{
    Serial.prinln("Message wasn't sent!");
   }
    mDetected=false;
  }
TempValue=analogRead(TempSensor);
Serial.println(TempValue);
delay(500);
}
