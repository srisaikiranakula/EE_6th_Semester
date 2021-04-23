const int window = 10;
const int inputPin = A0;
double readings[window];      
int currInd = 0;              
double sum = 0;                  
double average = 0;                

void setup() 
{ 
  pinMode(3,OUTPUT);
  pinMode(inputPin,INPUT);
  for (int i = 0; i < window; ++i)
  {
    readings[i] = 0;
  }
  Serial.begin(9600);
}

void loop() 
{ 
  sum -= readings[currInd];
  readings[currInd] = analogRead(inputPin);
  sum  = sum + readings[currInd];
  currInd = (currInd + 1)%window;
  average = sum / window;
  //Serial.println("input,output");
  Serial.print(readings[currInd]);
  Serial.print(",");
  Serial.println(average); 
  //Serial.print("\n");  
  analogWrite(3,average*0.25);     
}
