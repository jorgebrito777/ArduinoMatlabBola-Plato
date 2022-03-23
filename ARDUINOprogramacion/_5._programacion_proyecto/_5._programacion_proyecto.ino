#include <Servo.h>


 
#define Pecho 6
#define Ptrig 7
long duracion, distancia;   
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

-----------------------------------------------------------------------------------------
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(13, 1);
  
  servo1.attach(8);// Define el pin 3 como salida
  servo1.attach(9);
  servo1.attach(10);
  servo1.attach(11);
  }
  
void loop() {
  ------------------------------------------------------------------------//ultrasonico 1
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("---");                  // no mide nada
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(13, 0);               // en bajo el pin 13
  }
  
   if (distancia <= 10 && distancia >= 1){
    digitalWrite(13, 1);                     // en alto el pin 13 si la distancia es menor a 10cm
    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
----------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------- //control del servo
  servo1.write(0);// posicion del servo en cero
  delay(2000);
  servo1.write(180);//cambia la posicion del servo a 180
  delay(2000);
  
-------------------------------------------------------------------------------------- //control del servo
  servo2.write(0);// posicion del servo en cero
  delay(2000);
  servo2.write(180);//cambia la posicion del servo a 180
  delay(2000);
-------------------------------------------------------------------------------------- //control del servo
  servo3.write(0);// posicion del servo en cero
  delay(2000);
  servo3.write(180);//cambia la posicion del servo a 180
  delay(2000);
-------------------------------------------------------------------------------------- //control del servo
  servo4.write(0);// posicion del servo en cero
  delay(2000);
  servo4.write(180);//cambia la posicion del servo a 180
  delay(2000);

  ---------------------------------------------------------------------------------------
  }
  delay(400);                                // espera 400ms para que se logre ver la distancia en la consola
}
--------------------------------------------------------------------------------------------------------

