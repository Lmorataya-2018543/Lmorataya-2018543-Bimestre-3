
/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Control del brillo de un led 
   Dev: Landon Morataya
   Fecha: 08/06/2023
*/




#define led 6
#define pot A0

int intensidad, brillo;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
     intensidad=analogRead(pot);
 
     
     brillo=map(intensidad, 0, 1023, 0, 255);

     analogWrite(led, brillo);

}
