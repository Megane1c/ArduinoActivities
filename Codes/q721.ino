/*
Four(4) tactile switches named:
ROCK
PAPER
SCISSORS
RESET
Two(2) LED bulbs named:
WIN
LOSE
LCD SCREEN
The system will perform the following sequence:

Display the current score of the user and the Arduino at the bottom-right of the LCD(default = 0)
The system will prompt the user (via the TOP AREA of the LCD) to choose a button between ROCK, PAPER, and SCISSORS.
The device will randomly choose a move against the user.
The device will compare its choice against the input of the user, following the rules of rock-paper-scissors.
The device will Turn on the WIN LED bulb if the user wins the match, otherwise, the LOSE bulb will turn on.
The LCD will either say “YOU WIN, I CHOSE ROCK” or “YOU LOSE , I CHOSE ROCK” or “IT’S A TIE, I CHOSE ROCK” depending on the result of the match.
After the match, The device will wait for 5 seconds, then the device will repeat to step 1.
The RESET button will set the score back to the default value.

*/





// Including the library code
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initializing the library with the numbers of the interface pins


// Assigning the values
int btn[] = {10, 9, 8, 13}; //rock paper scissor reset
int led[] = {7, 6}; //win lose led
int choice;
int playerscore; //player
int cpuscore; //cpuscore


void setup()
{
  lcd.begin(16,2); // Setting the number of columns and rows of the LCD
  for(int i = 0; i < 4; i++) {
    pinMode(btn[i], INPUT);
  }
  for(int j = 0; j < 2; j++) {
    pinMode(led[j], OUTPUT);
  }
  lcd.setCursor(0,0);
  lcd.print("CHOOSE ROCK ");
  lcd.setCursor(0,1);
  lcd.print("PAPER OR SCISSORS");
  delay(2000);
  lcd.clear();
  

}


void loop()
{
  choice = random(1,4); //rock paper scisscors
  
  //read input
  int btn1 = digitalRead(btn[0]);
  int btn2 = digitalRead(btn[1]);
  int btn3 = digitalRead(btn[2]);
  int btn4 = digitalRead(btn[3]);
  
  
  //rock vs rock
  if (choice == 1 && btn1 == 1) {
    lcd.clear(); //clear lcd
    lcd.setCursor(0,0);
    lcd.print("I chose ROCK");
    lcd.setCursor(0,1);
    lcd.print("TIE");
    digitalWrite(led[1], HIGH);
    delay(5000);
    digitalWrite(led[1], LOW);
    
  }
  
  //paper vs rock
  else if (choice == 2 && btn1 == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose PAPER");
    lcd.setCursor(0,1);
    lcd.print("You Lose");
    digitalWrite(led[1], HIGH);
    delay(5000);
    digitalWrite(led[1], LOW);
    cpuscore++;
    
  }
  
  //scissors vs rock
  else if (choice == 3 && btn1 == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose SCISSORS");
    lcd.setCursor(0,1);
    lcd.print("You Win");
    digitalWrite(led[0], HIGH);
    delay(5000);
    digitalWrite(led[0], LOW);
    playerscore++;
    
  }
  
  //rock vs paper
  if (choice == 1 && btn2 == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose ROCK");
    lcd.setCursor(0,1);
    lcd.print("You Win");
    digitalWrite(led[0], HIGH);
    delay(5000);
    digitalWrite(led[0], LOW);
    playerscore++;
    
  }
  
  //paper vs paper
  else if (choice == 2 && btn2 == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose PAPER");
    lcd.setCursor(0,1);
    lcd.print("TIE");
    digitalWrite(led[1], HIGH);
    delay(5000);
    digitalWrite(led[1], LOW);
    
  }
  
  //scissors vs paper
  else if (choice == 3 && btn2 == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose SCISSORS");
    lcd.setCursor(0,1);
    lcd.print("You Lose");
    digitalWrite(led[1], HIGH);
    delay(5000);
    digitalWrite(led[1], LOW);
    cpuscore++;
    
  }
  
  //rock vs scissors
  if (choice == 1 && btn3 == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose ROCK");
    lcd.setCursor(0,1);
    lcd.print("You Lose");
    digitalWrite(led[1], HIGH);
    delay(5000);
    digitalWrite(led[1], LOW);
    cpuscore++;
    
  }
  
  //paper vs scissors
  else if (choice == 2 && btn3 == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose PAPER");
    lcd.setCursor(0,1);
    lcd.print("You Win");
    digitalWrite(led[0], HIGH);
    delay(5000);
    digitalWrite(led[0], LOW);
    playerscore++;
    
  }
  
  //scissors vs scissors
  else if (choice == 3 && btn3 == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I chose SCISSORS");
    lcd.setCursor(0,1);
    lcd.print("TIE");
    digitalWrite(led[1], HIGH);
    delay(5000);
    digitalWrite(led[1], LOW);
    
  }
  
  //score
  lcd.setCursor(11,1);
  lcd.print(playerscore);
  lcd.setCursor(12,1);
  lcd.print("-");
  lcd.setCursor(13,1);
  lcd.print(cpuscore);
  
  //reset
  if (btn4 == 1) {
    playerscore=0;
    cpuscore=0;
    lcd.clear();
  }
  
}
