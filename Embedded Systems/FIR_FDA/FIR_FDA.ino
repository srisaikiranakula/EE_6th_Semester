#include <avr/io.h>
const int window = 5;
double h[window] = {0.0874, 0.1014, 0.1064, 0.1014 ,0.0874};
const int inputPin = A0;
double a[window];      
double input;                             
double output = 0;   
double b,i,j;             

void setup() 
{
  // put your setup code here, to run once:
  // 0.0525    0.3102    0.4443    0.3102    0.0525
  //0.0663    0.2499    0.3676    0.2499    0.0663

  pinMode(3,OUTPUT);
  //pinMode(inputPin,INPUT);
  for (int i = 0; i < window; ++i)
  {
    a[i] = 0;
  }
  Serial.begin(9600);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  /*for(i=0;i<1;i+=0.01)
  {
    b = sin(2*PI*i)+0.001*random(100);
    input = b;
    int j;
    for(j=window-1;j>=1;--j)
    {
      a[j] = a[j-1];
    }
    a[0] = input;
    output = 0;
    for(j=0;j<window;++j)
    {
      output += h[j]*a[j];
    }
    Serial.println("input,output");
    Serial.print(b); 
    Serial.print(",");
    Serial.println(output); 
  }*/
  input = analogRead(inputPin);
  int j;
    for(j=window-1;j>=1;--j)
    {
      a[j] = a[j-1];
    }
    a[0] = input;
    output = 0;
    for(j=0;j<window;++j)
    {
      output += h[j]*a[j];
    }
    Serial.println("input,output");
    Serial.print(input); 
    Serial.print(",");
    Serial.println(output); 
}
