#include <OneWire.h>
#include <DallasTemperature.h>

const byte pinDatosDQ = 9;
const int analogInPin = A1;
int ledResistencia=2;
int ledVentilador=3;
char userInput;

OneWire oneWireObjeto(analogInPin);
DallasTemperature sensorDS18B20(&oneWireObjeto);

void setup() {
  Serial.begin(9600);
  sensorDS18B20.begin();
  pinMode(ledResistencia, OUTPUT);
  pinMode(ledVentilador, OUTPUT);
}

void loop() {
  sensorDS18B20.requestTemperatures();
  float tem=sensorDS18B20.getTempCByIndex(0);
  Serial.println(tem);
  delay(100);

  if (Serial.available()>0){
    userInput = Serial.read();
    
    if (userInput == 'w'){
      digitalWrite(ledResistencia, HIGH);
    }
    if (userInput == 'x'){
      digitalWrite(ledResistencia, LOW);
    }
    if (userInput == 'y'){
      digitalWrite(ledVentilador, HIGH);
    }
    if (userInput == 'z'){
      digitalWrite(ledVentilador, LOW);
    }
  }
}
