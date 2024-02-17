
bool input[4];
int sw[] = {10, 11, 12, 13};
int out[] = {2, 3, 4, 5, 6, 7, 8};
int in_seq;
int out_array[16][7] = { { 1,1,1,1,1,1,0 },    // 0
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

int in_array[16][4] = {  { 0,0,0,0 },    // 0
                         { 0,0,0,1 },    // 1
                         { 0,0,1,0 },    // 2
                         { 0,0,1,1 },    // 3
                         { 0,1,0,0 },    // 4
                         { 0,1,0,1 },    // 5
                         { 0,1,1,0 },    // 6
                         { 0,1,1,1 },    // 7
                         { 1,0,0,0 },    // 8
                         { 1,0,0,1 },    // 9
                         { 1,0,1,0 },    // A
                         { 1,0,1,1 },    // b
                         { 1,1,0,0 },    // C
                         { 1,1,0,1 },    // d
                         { 1,1,1,0 },    // E
                         { 1,1,1,1 }};   // F

void setup(){
 Serial.begin(9600);
 
 for (int i = 0; i < 7; i++){
    pinMode(i, OUTPUT);
  }
 
 for (int i = 0; i < 4; i++){
    pinMode(sw[i], INPUT);
  }
}

void loop(){
  
  //Read Binary Input
  for (int i = 0; i < 4; i++){
    input[i] = digitalRead(sw[i]);
  }
  
  //Search for equivalent Binary Sequence
  for (int i = 0; i < 17; i++){
    if (input[0] == in_array[i][0] && input[1] == in_array[i][1] && input[2] == in_array[i][2] && input[3] == in_array[i][3]) {
       in_seq = i;
       break;
    }
  }
  //Convert Binary to Hex
  for (int i = 0; i <8; i++){
    digitalWrite(out[i], out_array[in_seq][i]);
  }
}













