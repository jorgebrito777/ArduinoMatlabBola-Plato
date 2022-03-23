

#include <Servo.h>
#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13

Servo myservo;        // create servo object to control a servo 
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

              // this constant won't change.  It's the pin number
              // of the sensor's output:
int angle       = 179;
long distance;
long cm;
int val;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  myservo.attach(9);      // Servo conectado al pin 9
}

void loop()
{
  float cmMsec;       // creo una varaible floa cmMseg
  long microsec = ultrasonic.timing();   // leo el sensor ultrasónico. Respueta en microsegundos

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);  // convierto los microseg a CM usando una función de la librería
  
  if(angle < 0) {   // Si el angulo es negativo entonces el ángulo es igual a 180.
    angle = 179;
  }
  
  Serial.print("{d:");
  Serial.print(cmMsec);
  Serial.print(",r:");
  Serial.print(angle);
  Serial.print("}");    // imprimo CM y ángulo por el serial.
  
  //val = map(angle, 0, 180, 0, 179);  // esta funcion comvierte todo lo que este entre 0 y 180 a 0 y 179. 
  // al cambiar el if para los negativos a 179 esta función map esta de mas.

  myservo.write(val);        // envia ese angulo al servo
  
  angle -= 15;             // le quito 15 grados a la lectura de ángulo
  
  delay(100);            // demora de 100 mseg
}
