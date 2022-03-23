#include <Servo.h>
Servo servo;
void setup() {
  servo.attach(5);

}

void loop() {
int val = analogRead(3);//entrada de la pata de la mitad del potenciometro
val= map(val,0,1023,0,179);//mapea los datos del potenciometro donde 0 es el menor y 1023 el mayor , 0 es igual a cero y 1023 es igual a 179
servo.write(val);//saca el angulo para mover el servomotor
delay(15);
}
