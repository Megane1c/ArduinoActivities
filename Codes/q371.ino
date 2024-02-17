/*
Create a Tinkercad project with the following algorithm for an 
interactive program within the serial monitor:

1. The program asks the user to choose an mode of 
operation between "Arithmetic or Logic"

2.1  If "Arithmetic" was chosen the program will ask the 
user to choose from the following operation "+", "-", "x" "/"

2.2 If "Logic" was chosen the program will ask the 
user to choose from the following operation "AND" "OR" "NOT" XOR" "NAND" "NOR"

3. After choosing an operation, the program will ask the 
user to enter two input values (i.e. 1 and 2 [Arithmetic] or 1 and 0 [Logic]

4. The program then performs the chosen operation on the 
given input and return the result [i.e. 1+2=3 [Arithmetic] or 1 AND 0 = 0 [Logic]
*/


String operation, oparith, oplogic; //get user input of chosen operation
String num1, num2; //get user input for number
 
  
void setup()   
{  
    Serial.begin(9600);  
}  
  
void loop(){  
  
  //ASKING USER INPUT FOR CHOSEN MODE
  Serial.println("Enter chosen mode. (Arithmetic or Logic)");  
  while (Serial.available() == 0) {} //waits user input 
  operation = Serial.readString(); //Reading the Input string from Serial port.
  Serial.println("-------------------------");
  Serial.println("Mode of Operation: " + operation);
  Serial.println("-------------------------");
  operation.toLowerCase(); //converts string to lower case all the time 
  
  //IF STATEMENT FOR ARITHMETIC
  if (operation.equals("arithmetic")) {
    Serial.println("Enter chosen operation. (+, -, x, /)");
    while (Serial.available() == 0) {}
    oparith = Serial.readString();
    Serial.println("-------------------------");
    Serial.println("Operation chosen: " + oparith);
    
    //ADD
    if(oparith.equals("+")) {
      Serial.println("Enter first number.");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.");
      while (Serial.available() == 0) {} 
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      
      //OPERATION
      int sum = n1 + n2; 
      Serial.println("Sum of the Numbers: " + num1 + " + " + num2 + " = " + sum);
    }
    
    //SUBTRACT
    else if(oparith.equals("-")) {
      Serial.println("Enter first number.");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.");
      while (Serial.available() == 0) {}
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      
      //OPERATION
      int diff = n1 - n2;
      Serial.println("Difference of the Numbers: " + num1 + " - " + num2 + " = " + diff);
    }
    
    //MULTIPLY
    else if(oparith.equals("x")) {
      Serial.println("Enter first number.");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.");
      while (Serial.available() == 0) {}
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      
      //OPERATION
      int prod = n1 * n2;
      Serial.println("Product of the Numbers: " + num1 + " x " + num2 + " = " + prod);
    }
    
    //DIVIDE
    else if(oparith.equals("/")) {
      Serial.println("Enter first number.");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.");
      while (Serial.available() == 0) {}
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      
      //OPERATION
      int quot = n1 / n2;
      Serial.println("Quotient of the Numbers: " + num1 + " / " + num2 + " = " + quot);
    }
     
    
  }
  
  //IF STATEMENT FOR LOGIC
  if (operation.equals("logic")) {
    Serial.println("Enter chosen operation. (AND, OR, NOT, XOR, NAND, NOR)");
    while (Serial.available() == 0) {}
    oplogic = Serial.readString();
    Serial.println("-------------------------");
    Serial.println("Operation chosen: " + oplogic);
    oplogic.toLowerCase(); //converts string to lower case all the time
    
    //AND
    if(oplogic.equals("and")) {
      Serial.println("Enter first number.(0 or 1)");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.(0 or 1)");
      while (Serial.available() == 0) {}
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      bool res = n1 && n2; //result
      Serial.println("AND Result: " + num1 + " AND " + num2 + ": " + res);
    }
    
    //OR
    else if(oplogic.equals("or")) {
      Serial.println("Enter first number.(0 or 1)");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.(0 or 1)");
      while (Serial.available() == 0) {}
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      bool res = n1 || n2; //result
      Serial.println("OR Result: " + num1 + " OR " + num2 + ": " + res);
    }
    
    //NOT
    else if(oplogic.equals("not")) {
      Serial.println("Enter number. (0 or 1)");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Number: " + num1);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      bool res = !n1; //result
      Serial.println("NOT Result of " + num1 + ": " + res);
    }
    
    //XOR
    else if(oplogic.equals("xor")) {
      Serial.println("Enter first number.");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.");
      while (Serial.available() == 0) {}
      num2 = Serial.readString();
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      bool res = (n1 && !n2) || (!n1 && n2); //result
      Serial.println("XOR Result: " + num1 + " XOR " + num2 + " = " + res);
    }
    
    //NAND
    else if(oplogic.equals("nand")) {
      Serial.println("Enter first number.(0 or 1)");
      while (Serial.available() == 0) {}
      num1 = Serial.readString();  //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.(0 or 1)");
      while (Serial.available() == 0) {}
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      bool res = !(n1 && n2); //result
      Serial.println("NAND Result: " + num1 + " NAND " + num2 + ": " + res);
    }
    
    //NOR
    else if(oplogic.equals("nor")) {
      Serial.println("Enter first number.(0 or 1)");
      while (Serial.available() == 0) {}
      num1 = Serial.readString(); //Reading FIRST NUMBER Input from Serial port.
      Serial.println("Enter second number.(0 or 1)");
      while (Serial.available() == 0) {}
      num2 = Serial.readString(); //Reading SECOND NUMBER Input from Serial port.
      Serial.println("-------------------------");
      Serial.println("Numbers: " + num1 + " and " + num2);
      Serial.println("-------------------------");
      
      //CONVERTS STRING TO INT
      int n1 = num1.toInt();
      int n2 = num2.toInt();
      bool res = !(n1 || n2); //result
      Serial.println("NOR Result: " + num1 + " NOR " + num2 + ": " + res);
    }
   
  }

  
}