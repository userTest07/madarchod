#include<p18f4550.h>
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
void myMsDelay (unsigned int time)
{
unsigned int i, j;
for (i = 0; i < time; i++)
for (j = 0; j < 275; j++);/*Calibrated for a 1 ms delay in MPLAB*/
}
void main()
{
TRISCbits.TRISC2 = 0 ; // Set PORTC, 2 as output
 TRISCbits.TRISC6 = 0 ;
TRISCbits.TRISC7 = 0 ;
PR2 = 0x7F; // set PWM period to Maximum value
 CCPR1L = 0x12; // Initalise PWM duty cycle to 00
 CCP1CON = 0x3C; // Configure CCP1CON as explained above.
T2CON = 0x07;
myMsDelay(50);
CCPR1L = 0x7F;
myMsDelay(50);
PORTCbits.RC6 = 1;
 PORTCbits.RC7 = 0;
 while(1)
{
CCPR1L = 0x0F;
myMsDelay(50);
CCPR1L = 0x1F;
myMsDelay(50);
CCPR1L = 0x2F;
myMsDelay(50);
CCPR1L = 0x3F;
myMsDelay(50);
CCPR1L = 0x4F;
myMsDelay(50);
CCPR1L = 0x5F;
myMsDelay(50);
CCPR1L = 0x6F;
}
}
