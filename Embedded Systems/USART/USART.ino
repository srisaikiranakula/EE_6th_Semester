#include <avr/io.h>                         // header file 
unsigned char req[]="I I T Kharagpur\n";    // string in a character array
unsigned char length = 16;                  //  the string has 16 charecters
unsigned char i=0;                          //  index for traversing through the string

void setup() 
{
                                              // put your setup code here, to run once:
  UCSR0B |= (1<<TXEN0);                       //TXEN0-Transmitter Enable (Tx pin)
  UCSR0C &= (~(1<<UMSEL01))|(~(1<<UMSEL00))| (~(1<<USBS0)) | (~(1<<UPM00)) | (~(1<<UPM01));  
                                              //UMSEL01:UMSEL00 = 0b00 -> Asynchronous Mode
                                              //  USBS0 =  0    -->  1-stop bit
                                              //  UPM01:00 = 00 -->  0-parity bit
  UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);          //  UCSZ02:UCSZ00  = 0b011  -> 8-bit 
                                              
                                              

  UBRR0H = 0x00;                              //Buad Rate (Bd) = fosc/(16(UBRRn + 1), fosc = 16MHz, 
  UBRR0L = 0x67;  
                                              //Baud Rate = 300     UBRRn = ((10^6)/300)-1    = 3332  = 0xD04
                                              //Baud Rate = 1200    UBRRn = ((10^6)/1200)-1   = 832   = 0x340
                                              //Baud Rate = 2400    UBRRn = ((10^6)/2400)-1   = 415   = 0x19F
                                              //Baud Rate = 4800    UBRRn = ((10^6)/4800)-1   = 207   = 0xCF
                                              //Baud Rate = 9600    UBRRn = ((10^6)/9600)-1   = 103   = 0x67
                                              //Baud Rate = 19200   UBRRn = ((10^6)/19200)-1  = 51    = 0x33
                                              //Baud Rate = 38400   UBRRn = ((10^6)/38400)-1  = 25    = 0x19
                                              //Baud Rate = 57600   UBRRn = ((10^6)/57600)-1  = 16    = 0x10
                                              //Baud Rate = 74880   UBRRn = ((10^6)/74880)-1  = 12    = 0x0C
                                              //Baud Rate = 115200  UBRRn = ((10^6)/115200)-1  = 7    = 0x07
}

void loop() 
{
  // put your main code here, to run repeatedly:
  while(!(UCSR0A & (1<<UDRE0)));  // wait till UDR is empty 
    
  UDR0 = req[i];                  // send the ASCII charecter
  i = (i+1)%length;               // prepare the index for the next ASCII charecter
  
}
