int ledpins[] = {9, 8, 7, 6, 5, 4, 3, 2}; //LED pins, left-most LED is MSB
int i = 0; //initial value


void setup() {
  Serial.begin(9600);
  
  //LED pinmode
  for (int j = 0 ; j < 8 ; j++) {
 	pinMode(ledpins[j], OUTPUT);
  }
   
}

//Fibonacci sequence generator
int fiboseq(int startval) {
  if (startval <=1) {
    return startval;
  }
  else {
    return fiboseq(startval - 1) + fiboseq(startval - 2);
  }
}

void loop()
{
  //if statement to reset fibonacci sequence
  //maximum 8-bit
  if (fiboseq(i) > 255) {
    i = 0;
  }
  
  //representing fibonacci output using a variable
  int dec = fiboseq(i);
  showLED(dec);
  Serial.println(fiboseq(i)); //prints fibonacci sequence
  delay(2000); //2 second delay
  i++;
}

//binary LED output
void showLED(byte numtobin)
{
  for (int j = 0; j < 8; j++)
  {
    //if-else statement for representing binary as LED output
    if (bitRead(numtobin, j) == 1)
    {
      digitalWrite(ledpins[j], HIGH); //turns on LED
    }
    else
    {
      digitalWrite(ledpins[j], LOW); //turns off LED
    }
  }
  
}