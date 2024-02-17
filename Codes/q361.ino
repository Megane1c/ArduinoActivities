//Create a tinkercad project with the following algorithm:
//1. LED blinks with delay of 0.5 seconds 
//2. After 5 blinks the delay increases by 0.5 seconds
//3. Repeat 2 continuously until 10 second delay is achieved.

//Variables
int ledpin = 10; //LED pin number
int count = 5; //5 blink counts
int time = 500; // 0.5 sec delay

void setup()
{
  pinMode(ledpin, OUTPUT); //LED as output
}

void loop()
{
  //While loop used to count the blinks
  while(count > 0) {
    digitalWrite(ledpin, HIGH); //turns on LED
    delay(time);
    digitalWrite(ledpin, LOW); //turns off LED
    delay(time);
    count--; //decreases count by 1
  }
  //If statement - adds 0.5 sec delay and resets blink counter
  if (count == 0) {
    time += 500;
    count = 5;
  }
  //If statement - resets the delay time after having 10sec delay
  if (time > 10000) {
    time = 500;
  
  }

}