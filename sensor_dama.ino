#include <OneWire.h>//library Onewire
#include <DallasTemperature.h>//library DallasTemperature

#define one_wire_bus 5 // dakhele pin 5
OneWire onewire(one_wire_bus);
DallasTemperature sensor(&onewire);
float temp;
int idpin = 4;

void setup() {
  // put your setup code here, to run once:
pinMode(idpin, OUTPUT);
Serial.begin (9600);//data hai ke sensor midero bebinim
Serial.println("Dallas temperature ic control library demo");
sensor.begin();// rah andazi sensor
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print ("requesting  Temperatures ....");
sensor.requestTemperatures();
Serial.print ("DONE");
Serial.print("Temperature is : ");
temp= sensor.getTempCByIndex(0);// bekhater in ke ke ma yek sensor darim baraye hamin  az sefr shoro kardim
Serial.print(temp);// meghdaro vase ma chap kone
if(temp>= 27){
  digitalWrite(idpin.HIGH);
}else{
  digitalWrite(idpin.HIGH);
}
delay (1000);
}
