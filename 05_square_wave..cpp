#include<p18f458.h>
#define mybit PORTBbits.RB4
#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=ON
#pragma config LVP=OFF
void main(void);
void Timerdelay(void);
void main()
{
TRISBbits.TRISB4=0;
while(1)
{
mybit^=0;
mybit = ~mybit;
Timerdelay();
}
}
void Timerdelay()
{
T0CON =0x07;
TMR0H = 0xFF;
TMR0L = 0xF0;
INTCONbits.TMR0IF =1;
T0CONbits.TMR0ON =1;
while(INTCONbits.TMR0IF==0)
INTCONbits.TMR0IF=0;
T0CONbits.TMR0ON =0;
}
