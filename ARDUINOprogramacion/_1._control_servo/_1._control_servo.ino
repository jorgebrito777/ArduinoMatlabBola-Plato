#include <Servo.h>

Servo servo1;//variables servo
Servo servo2;
void setup(){
servo1.attach(3);//pin de salida 3
servo2.attach(4);//pin de salida 4

}

void loop(){
  servo1.write(0);// posicion del servo en cero
  servo2.write(0);
  delay(2000);
  servo1.write(90);//cambia la posicion del servo1 a 90
  servo2.write(90);//cambia la posicion del servo2 a 90
  delay(2000);
  }
