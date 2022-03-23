
#include <math.h>

#include "Wire.h"
#include "WiiChuck.h"
//#include "nunchuck_funcs.h"

#define MAXANGLE 90
#define MINANGLE -90


WiiChuck chuck = WiiChuck();
int angleStart, currentAngle;
int tillerStart = 0;
double angle;

void setup() {
  //nunchuck_init();
  Serial.begin(115200);
  chuck.begin();
  chuck.update();
  chuck.calibrateJoy();
}


void loop() {
  delay(20);
  chuck.update(); 
  
    Serial.print("Joystick X:");
    Serial.print(chuck.readJoyX());
    Serial.print("-");  
    Serial.print("Joystick Y:");
    Serial.print(chuck.readJoyY());
    Serial.print("-");  
    Serial.print("Rotacion sobre eje :");  
    Serial.print(chuck.readRoll());
    Serial.print("-");
    Serial.print("Rotacion sobre eje :");   
    Serial.print(chuck.readPitch());
    Serial.print("-");  
    Serial.print("Acelerometro X:"); 
    Serial.print((int)chuck.readAccelX()); 
    Serial.print(", ");  
    Serial.print("Acelerometro Y:"); 
    Serial.print((int)chuck.readAccelY()); 
    Serial.print("-");  
    Serial.print("Acelerometro Z:"); 
    Serial.print((int)chuck.readAccelZ()); 
    Serial.print("-   ");
    Serial.print("boton: ");
    if (chuck.buttonZ) {
     Serial.print("Z");
    } else  {
     Serial.print("-");
    }
    Serial.print(", ");  
    if (chuck.buttonC) {
     Serial.print("C");
    } else  {
     Serial.print("-");
    }

    Serial.println();

}
 
