/*
The system will perform the following sequence:

1. A user presses the button for 5 seconds

2. After 5 seconds of pressing the button, the GREEN LED will turn on continuously, and the RED LED will turn off and the buzzer should alarm. The LCD should also say. "The Green team captured this hill"

3. If the button is pressed again for 5 seconds, the LED will turn on continuously, and GREEN LED will turn off, and the buzzer should alarm. The LCD should also say. "The RED team captured this hill"

4. Repeat 2 if the button is pressed again.

 

*/





// Including the library code
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initializing the library with the numbers of the interface pins


// Assigning the values
int btn = 10; //input
int led[] = {7, 6}; //green and red
int buzz = 13; //buzzer
int greenfirst = 0;
int timer=5000; //5sec timer
char * green = "                  The Green team captured this hill.                "; //green team message
char * red = "                  The Red team captured this hill.                "; //red team message


void setup()
{
  lcd.begin(16,2); // Setting the number of columns and rows of the LCD
  
  //input and output
  pinMode(btn, INPUT);
  pinMode(buzz, OUTPUT);
  for(int j = 0; j < 2; j++) {
    pinMode(led[j], OUTPUT);
  }
 
}


void loop() {
  
  //green team
  while (digitalRead(btn) == 1 && greenfirst == 0) {
    timer -= 1000;
    delay(1000);
    if (timer == 0) {
      digitalWrite(led[0], HIGH); //green ON
      digitalWrite(led[1], LOW); //red OFF
      buzzersound();
      for (int i = 0; i <= strlen(green) - 16; i++){
    	greenteam(0, i);
 	 }
      greenfirst = 1;
      timer = 5000;
    }
       
  }
  
  //red team 
  while (digitalRead(btn) == 1 && greenfirst == 1) {
    timer -= 1000;
    delay(1000);
    if (timer == 0) {
      digitalWrite(led[1], HIGH); //red ON
      digitalWrite(led[0], LOW); //green OFF
      buzzersound();
      for (int i = 0; i <= strlen(red) - 16; i++){
    	redteam(0, i);
 	 }
      greenfirst = 0;
      timer = 5000;
    }
       
  }

  
  
}
//buzzer
void buzzersound() {
  tone(buzz, 1000);
  delay(1000); // 1 second sound
  noTone(buzz);
}

void greenteam(int print, int start){

  lcd.setCursor(print, 0);
  
  //print letters in section
  for (int j = start; j <= start + 15; j++) 
  {
    lcd.print(green[j]);
  }
  lcd.print(" ");
  delay(150);
}

void redteam(int print, int start){

  lcd.setCursor(print, 0);
  
  //print letters in section
  for (int j = start; j <= start + 15; j++) 
  {
    lcd.print(red[j]);
  }
  lcd.print(" ");
  delay(150);
}