int
proxi,
ledsegment[] = {2, 3, 4, 5, 6, 7, 8},
out_array[16][7] = { { 1,1,1,1,1,1,0 },    // 0
                     { 0,1,1,0,0,0,0 },    // 1
                     { 1,1,0,1,1,0,1 },    // 2
                     { 1,1,1,1,0,0,1 },    // 3
                     { 0,1,1,0,0,1,1 },    // 4
                     { 1,0,1,1,0,1,1 },    // 5
                     { 1,0,1,1,1,1,1 },    // 6
                     { 1,1,1,0,0,0,0 },    // 7
                     { 1,1,1,1,1,1,1 },    // 8
                     { 1,1,1,0,0,1,1 },    // 9
                     { 1,1,1,0,1,1,1 },    // A
                     { 0,0,1,1,1,1,1 },    // b
                     { 1,0,0,1,1,1,0 },    // C
                     { 0,1,1,1,1,0,1 },    // d
                     { 1,0,0,1,1,1,1 },    // E
                     { 1,0,0,0,1,1,1 }};   // F

//read proximity
long proximity(int trigpin, int echopin){
	pinMode(trigpin, OUTPUT);	
    digitalWrite(trigpin, LOW);
	delayMicroseconds(2);			
    digitalWrite(trigpin, HIGH);
	delayMicroseconds(10);			
    digitalWrite(trigpin, LOW);
	pinMode(echopin, INPUT);		
    return pulseIn(echopin, HIGH);
}

void setup(){

  //output 7 segment
  for(int i = 0; i < 7; i++){
     pinMode(ledsegment[i], OUTPUT);
  }
}

void loop(){
  //map proximity sensor's distance to hex value
  proxi = (proximity(13,13))/1302;
  delay(100);
  for (int j = 0; j < 7; j++) {
	digitalWrite(ledsegment[j], (out_array[proxi][j]));
  }

}
  






