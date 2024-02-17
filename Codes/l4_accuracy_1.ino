// Including the library code
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initializing the library with the numbers of the interface pins


// Assigning the values
int PPin1 = A0;
int PV;
int PV1;
float Vi = 5;
float Rref = 1000;
float Vo;
float R;


void setup()
{
  lcd.begin(16,2); // Setting the number of columns and rows of the LCD
  pinMode(PPin1, INPUT); //new potentiometer as input

}


void loop()
{
 
  PV = analogRead(PPin1); // Reading the value of potentiometer
  
  PV1 = map(PV, 0, 1023, 1023, 0);

  lcd.print("PV: "); // Printing "PV:" as potentiometer value indicator
  lcd.print(PV); // Printing the potentiometer value in Byte
  lcd.print(" Bytes"); // Printing "Bytes" as unit

  Vo = ((Vi*PV)/1023); // Equating output voltage
  R = Rref*((Vi/Vo) - 1); // Equating resistance
 
  lcd.setCursor(0,1); // Setting the cursor to column 0, line 1
  lcd.print("R: "); // Printing "R:" as resistance indicator
  lcd.print(R); // Reading the computed value
  lcd.print(" ohms"); // Printing "ohms" as unit
  delay(1000);
  lcd.clear();
  
  

}