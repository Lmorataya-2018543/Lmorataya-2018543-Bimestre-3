/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Interrupciones por medio de software
   Dev: Landon Morataya
   Fecha: 08/06/2023
*/


//Librerias
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>



//Directivas de Preprocesado
#define boton 3
//Funcion ISR
void sensortemp();
void MA_boton();



//Constructores
Ticker accion_temperatura(sensortemp,2900);
Ticker state_boton(MA_boton,6000);
OneWire ourWire(4);
DallasTemperature sensor(&ourWire);


void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  accion_temperatura.start();
  state_boton.start();
  sensor.begin();
}

void loop() {
  accion_temperatura.update();
  state_boton.update();
}


void sensortemp(){
  sensor.requestTemperatures();  
  float temp= sensor.getTempCByIndex(0); 
  Serial.println("Sensor de Temperatura");
  Serial.print("La Temeperatura es: ");
  Serial.print(temp);
  Serial.println(" C");
}



void MA_boton(){
  int estado = digitalRead(boton);


 
  if(estado == HIGH){
    Serial.println("El boton esta");
    Serial.println("Encendido");
    
  }


  if(estado == LOW){
    Serial.println("El boton esta");
    Serial.println("apagado");



    
  }
}
