/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Control de una secuencia de colores RGB LANDON
   Dev: Landon Morataya
   Fecha: 08/06/2023
*/

#define R 3
#define G 5
#define B 6
#define P A0

int variacion, tiempo;


void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(P, INPUT);


}

void loop() {

 tiempo=map(analogRead(P), 0, 1023, 100, 255);

 analogWrite(R,174);
 analogWrite(G, 92);
 analogWrite(B,230);
    delay(tiempo);
    
 analogWrite(R,255);
 analogWrite(G,255);
 analogWrite(B,255);
    delay(tiempo);

 analogWrite(R,0);
 analogWrite(G,255);
 analogWrite(B,255);
    delay(tiempo);

 analogWrite(R,189);
 analogWrite(G,174);
 analogWrite(B,20);
    delay(tiempo);

 analogWrite(R,225);
 analogWrite(G, 07);
 analogWrite(B,35);
    delay(tiempo);


}
