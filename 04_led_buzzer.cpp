#include <p18f4520.h>
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#define lrbit PORTBbits.RB4 //SW0 interfaced to RB4
#define rlbit PORTBbits.RB5 //SW1
#define buzzer PORTCbits.RC2
#define relay PORTCbits.RC1
void MsDelay (unsigned int time)
{
 unsigned int i, j;
 for (i = 0; i < time; i++)
 for (j = 0; j < 275; j++);/*Calibrated for a 1 ms delay in MPLAB*/
}
void main()
{
 unsigned char val=0;
 INTCON2bits.RBPU=0; //To Activate the internal pull on PORTB
 ADCON1 = 0x0F; //To disable the all analog inputs
 TRISBbits.TRISB4=1; //To configure RB4 as input
 TRISBbits.TRISB5=1; //To configure RB5 as input
 TRISCbits.TRISC1=0; //To configure RC1 (relay) as output
 TRISCbits.TRISC2=0; //To cofigure RC2 (buzzer) as output
 TRISD = 0x00; // To cofigure PORTD (LED) as output
 PORTD = 0x00; //Initial Value for LED
 buzzer = 0; //Initial Value for Buzzer
 relay = 0; //Initial Value for Relay
while (1)
 {
 if (!(lrbit)) // if (lrbit == 0) //To check whether SW0 is pressed
 val = 1; // Latch the SWO
 if (!(rlbit)) //To check whether SW1 is pressed
 val = 2; // Latch the SW1
 if (val == 1)
 {
 buzzer = 1;
 relay = 1;
 PORTD = PORTD >>1; //Shift left by 1 bit
 if (PORTD == 0x00)
 PORTD = 0x80; // Make the MSB bit eqaul to 1
 MsDelay(250);
 }
 if (val == 2)
 {
 buzzer = 0;
 relay = 0;
 PORTD = PORTD<<1; //Shift right by 1 bit
 if (PORTD == 0x00)
 PORTD = 0x01; // Make the LSB bit eqaul to 1
 MsDelay(250);
 }
 }
}
