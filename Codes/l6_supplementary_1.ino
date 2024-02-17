int 
btn[] = {13, 12, 9, 8}, //button pins
led[] = {4, 3, 2}, //led pins MSB to LSB
btn1val, btn2val, btn3val, btn4val, //button value
btn1valinv, btn2valinv, btn3valinv, btn4valinv, //inverted button value
firstval, secondval, outputval; //values


void setup() {
  Serial.begin(9600); 
  
  //button pins as input
  for (int i = 0; i < 4; i++) {
    pinMode(btn[i], INPUT);
  }
  //led pins as output
  for (int j = 0; j < 3; j++) {
    pinMode(led[j], OUTPUT);
  }
  
}

void loop() {
  //reading button values 
  btn1val = digitalRead(btn[0]);
  btn2val = digitalRead(btn[1]);
  btn3val = digitalRead(btn[2]);
  btn4val = digitalRead(btn[3]);

  //assigning new variable to invert
  btn1valinv = btn1val;
  btn2valinv = btn2val;
  btn3valinv = btn3val;
  btn4valinv = btn4val;
 
  //if statement for inverting
  if (btn1val == 0){
    btn1valinv = 1;
  }
  else {
    btn1valinv = 0;
  }

  if (btn2val == 0){
    btn2valinv = 1;
  }
  else {
    btn2valinv = 0;
  }

  if (btn3val == 0){
    btn3valinv = 1;
  }
  else {
    btn3valinv = 0;
  }
  
  if (btn4val == 0){
    btn4valinv = 1;
  }
  else {
    btn4valinv = 0;
  }
 
  //setting old variable into inverted value
  btn1val = btn1valinv;
  btn2val = btn2valinv;
  btn3val = btn3valinv;
  btn4val = btn4valinv;
 
  
  //prints first value
  Serial.print("First: ");     
  Serial.print(btn1val);
  Serial.println(btn2val);
  
  //prints second value
  Serial.print("Second: ");
  Serial.print(btn3val);
  Serial.println(btn4val);
  
  //changing binary value to decimal 
  firstval = (btn1val*2)+(btn2val*1);  
  secondval = (btn3val*2)+(btn4val*1);

  //output value
  outputval = firstval + secondval;    
  Serial.print("Total: ");   //printing total value in serial port to check
  Serial.println(outputval);
  Serial.println("-------------");
  
  delay(500);
  
      //reseting output LEDs
  for (int k = 0; k < 3; k++) {
    digitalWrite(led[k], LOW);
  }

  if (outputval >= 4) {              
    digitalWrite(led[0] ,HIGH);
    outputval -= 4;
  }
  
  if (outputval >= 2) {              
    digitalWrite(led[1],HIGH);
    outputval -= 2;
  }
  
  if (outputval >= 1) {              
    digitalWrite(led[2],HIGH);
    outputval -= 1;
  }
 
 
}