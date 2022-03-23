#include <Servo.h>


 
#define Pecho 6
#define Ptrig 7
long duracion, distancia;   
Servo servo1; 
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(13, 1);
  servo1.attach(3);// Define el pin 13 como salida
  }
  
void loop() {
  
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


  servo1.write(180);// posicion del servo en cero
  delay(200);
  servo1.write(0);//cambia la posicion del servo1 a 90
  delay(200);
  
  }
  delay(400);                                // espera 400ms para que se logre ver la distancia en la consola
}
