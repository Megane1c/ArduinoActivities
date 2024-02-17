/*
Create a Tinkercad project where you can vary the brightness of an 
LED light using buttons. 
(Hint use analogWrite to vary brightness and use the button as counter)
*/

int ledpin =  9; //LED pin
int brUP = 2;  //Pushbutton pin (up)
int brDOWN = 13; //Pushbutton pin (down)
 
int max = 50; //max value for brightness

int br = max/2; //variable for brightness (setting it at half brightness on first run)

void setup() {
  pinMode(ledpin, OUTPUT); //LED as output      

  //Pushbutton as input
  pinMode(brUP, INPUT);     
  pinMode(brDOWN, INPUT);   

}

void loop(){
  
  //IF statement for increasing brightness
  if (digitalRead(brUP) == HIGH && br < max){ 
    br++;
  }
  
  //IF statement for decreasing brightness
  if (digitalRead(brDOWN) == HIGH && br > 0){
    br--;
  }
  
  
  delay(100); //delay
  
  //scaling maximum brightness to analogWrite scale (0 to 255)
  analogWrite(ledpin, map(br, 0, max, 0, 255));    
    
  
}


