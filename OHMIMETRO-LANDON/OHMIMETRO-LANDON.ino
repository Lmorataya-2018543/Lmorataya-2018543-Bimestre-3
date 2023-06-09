
/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: OHMIMETRO
   Dev: Landon Morataya
   Fecha: 09/06/2023
*/


#include <LiquidCrystal_I2C.h>
#define voltaje A0


int   vcc=5;
int   R2 = 10000;
float R1 = 0;
float vout = 0;
float lectura = 0; 
float valor  = 0;
float conver = 0; 


LiquidCrystal_I2C lcd(0x27, 16 , 2);
void conversion ();



void setup() {
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  conversion();
  
  }
  void conversion()
{
 
 lectura= analogRead(voltaje);

 conver=lectura * vcc;
 vout=conver / 1023;
 
 valor= (vcc - vout)/vout;
 R1=R2 * valor;
R1=R1+10;

if(lectura)
{
 
  lcd.setCursor(0,0);
  lcd.print("el valor es:");
  lcd.setCursor(10,1);
  lcd.print("ohms");
  lcd.setCursor(2,1);
  lcd.print(R1);
  
  }
  if(lectura)
  {
  lcd.setCursor(0,0);
  lcd.print("el valor es:");  
    
  }
}
