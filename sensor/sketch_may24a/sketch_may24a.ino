#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int lcd_key     = 0;
int adc_key_in  = 0;
int key = 0;


int read_LCD_buttons()  // para leer los botones


  { adc_key_in = analogRead(0);      // Leemos A0
    // Mis botones dan:  0, 145, 329,507,743
    // Y ahora los comparamos con un margen comodo

  }
  void setup()
   {  lcd.begin(16, 2);    
   // Inicializar el LCD
   lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("hola jorge");     // print a simple message
lcd.setCursor(1,1);
lcd.print("");    
   }
   void loop()
   {            // Cursor a linea 2, posicion 1
 

 lcd.setCursor(16,1);
 lcd.autoscroll();
 lcd.print(" ");
 delay(300);

     
   }
