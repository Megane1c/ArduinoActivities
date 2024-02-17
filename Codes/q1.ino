/* Create a Tinkercad project that functions as a gameshow buzzer system. 
   The rules are the following:

1. Connect 3 buttons, 3 LEDs, and 1 buzzer to an Arduino.  
   1 LED will be assigned to 1 button. 
   the buzzer is going to on once a button is press, regardless of who press it.

2. At the start, the program will wait for someone to press the button.

3. Once the button is press, the buzzer should ring.

4.  Turn on the LED of the button the pressed first.

5. Once someone already the pushed the button, no one can push anymore.

6. 10 seconds after the button was pressed, Everything is reset. then repeat step 2.

*/

int time = 10000; //10 second time
int btn[] = {2, 3, 4}; //button pins
int led[] = {5, 6, 7}; //LED pins
int buzz = 8; //buzzer pin

void setup()
{
  
  for (int i = 0; i < 3; i++){
    pinMode(btn[i], INPUT); //setting button pins as INPUT
   } 
  
  for (int i = 0; i < 3; i++){
    pinMode(led[i], OUTPUT); //setting LED pins as OUTPUT
   }   
  
  pinMode(buzz, OUTPUT); //buzzer
}

void loop()
{
  //reads every button input
  int btn1 = digitalRead(btn[0]);
  int btn2 = digitalRead(btn[1]);
  int btn3 = digitalRead(btn[2]);

  //button 1 pressed first
  while (btn1 == HIGH) {
    digitalWrite(led[0], HIGH); //turns on LED
    buzzersound();
    
    delay(time); //time delay
    digitalWrite(led[0], LOW); //turns off LED 
    return;
 
  }
  
  //button 2 pressed first
  while (btn2 == HIGH) {
    digitalWrite(led[1], HIGH); //turns on LED
    buzzersound();

    delay(time); //time delay
    digitalWrite(led[1], LOW); //turns off LED
    return;
  }
  
  //button 3 pressed first
   while (btn3 == HIGH) {
     digitalWrite(led[2], HIGH); //turns on LED
     buzzersound();
    
     delay(time); //time delay
     digitalWrite(led[2], LOW); //turns off LED 
     return;
   }
}

//buzzer sound setup
void buzzersound() {
  tone(buzz, 1000);
  delay(1000); // 1 second sound
  noTone(buzz);
}