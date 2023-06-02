/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: contador de 0-50
   Dev: Landon Morataya
   Fecha: 01/06/2023
*/

//Directivas de Propocesador
#define btn_en_alto 2
#define btn_en_bajo 3 
#define A 4
#define B 5
#define C 6
#define D 7

#define A1 8
#define R1 9
#define D1 10
#define U1 11

//Funciones
void funcion_ISR_rising(void);
void funcion_ISR_falling(void);
void display_primero();
void display_segundo();

//Variables
volatile static bool f_print = false;
int unidades = 0;
int decenas = 0; 

void setup() {
  pinMode(btn_en_alto, INPUT);
  pinMode(btn_en_bajo, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(U1, OUTPUT);
 
  attachInterrupt(digitalPinToInterrupt(btn_en_alto),funcion_ISR_rising,RISING);
  attachInterrupt(digitalPinToInterrupt(btn_en_bajo),funcion_ISR_falling,FALLING); 
}
void loop() {
  if(f_print){
    f_print = false; //Limpio la variable
    if(unidades > 9){
      decenas++;
      unidades = 0;
    }
    if(unidades == -1){
      unidades = 9;
      decenas--;
    }
    if(decenas < 0){
      unidades = 0;
      decenas = 5;
    }
    if(unidades > 0 && decenas == 5){
      unidades = 0;
      decenas = 0;
    }
   
  }
  display_primero();
  display_segundo();
}
//Funciones ISR
void funcion_ISR_rising(void){
  unidades ++; //aunmento el valor de la variable
  f_print = true;
}
void funcion_ISR_falling(void){
  unidades --; //disminuyo el valor de la variable  
  f_print = true;
}
void display_primero(){
  if(unidades==0){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  }
  
   if(unidades==1){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  }
 
  if(unidades==2){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  }
  
  if(unidades==3){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  }

  if(unidades==4){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  }
 
  if(unidades==5){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  }
 
  if(unidades==6){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  }
 
  if(unidades==7){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  }
 
  if(unidades==8){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  }
 
  if(unidades==9){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  }
}
void display_segundo(){
  if(decenas==0){
    digitalWrite(A1, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(U1, LOW);
  }
 
  if(decenas==1){
  digitalWrite(A1, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(U1, HIGH);
  }
 
  if(decenas==2){
  digitalWrite(A1, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(D1, HIGH);
  digitalWrite(U1, LOW);
  }

  if(decenas==3){
  digitalWrite(A1, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(D1, HIGH);
  digitalWrite(U1, HIGH);
  }  

  if(decenas==4){
  digitalWrite(A1, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(U1, LOW);
  }

  if(decenas==5){
  digitalWrite(A1, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(U1, HIGH);
  }
}
