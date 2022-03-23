#include <Ultrasonic.h>

#include <Servo.h>

      //Incluimos la libreria Servo
  //Incluimos la libreria Ultrasonico

Servo servo1;          //Declaramos nuestro servo
Ultrasonic ultraso (6, 7);  //Declaramos los pines del ultrasonico
int distancia;          //Declaramos una constante
int pausa;          //Declaramos una cosntante


void setup (){
  
servo1.attach(8);    //Declaramos el pin de nuestro servo
Serial.begin(9600);
}

void loop()
{
  distancia =  ultraso.Ranging(CM); //Medimos la distancia del Ultrasonico
if (distancia < 10){              //Si la distancia es menor a 10 cm el servo se situa a 90º
pausa = ultraso.Ranging(CM) *10; 
servo1.write (90);
   delay(1000); 
}
else if (distancia >10){    //Si la distancia es mayor a 10 cm el servo se situa donde le indica la siguiente orden del programa
servo1.write (0);          //Ponemos el servo a 0º
delay(1000);
}

distancia =  ultraso.Ranging(CM);
if( distancia < 10){          //Si la distancia es menor a 10 cm  
pausa = ultraso.Ranging(CM) *10; //Decimos que el servo se ponga a 90º
servo1.write (90);
   delay(1000);
}
else if (distancia >10){
servo1.write(180);
delay(1000);
}
Serial.print("  Distancia estimada: "); //Comandos para ver en pantalla la distancia al cual está el obstaculo
Serial.print(distancia);
Serial.println(" cm");


}
