#include <msp430.h>

void turnRWheelFWD(void );
void turnLWheelFWD(void);
void goForward(void);
void goBackward(void);
void stopRobot(void);

void main(void) {
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    P1DIR &= ~BIT3;
    P1REN |= BIT3;

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// Turns on L wheel

    P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
    P2SEL |= BIT4;							// Turns on R wheel

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period



    while (1) {

    	goForward();
    	goBackward();
    	turnRWheelFWD();
    	turnLWheelFWD();

    	//while((P1IN & BIT3) != 0);			// Wait for a button press
    	//while((P1IN & BIT3) == 0);			// and release

        //TA1CCR1 = (TA1CCR1 + 0x010) & 0xFF;	// increase duty cycle
        //TA1CCR2 = (TA1CCR2 + 0x010) & 0xFF;	// decrease duty cycle

    } // end loop
} // end main

void turnRWheelFWD(void )
{
	TA1CCR1 = 0X0020;
	TA1CCTL1 = OUTMOD_7;

	 TA1CCR2 = 0x0020;
	 TA1CCTL2 = OUTMOD_3;

}
void turnLWheelFWD(void)
{
	TA1CCR1 = 0X0020;
	TA1CCTL1 = OUTMOD_3;

	TA1CCR2 = 0x0020;
	TA1CCTL2 = OUTMOD_7;

}
void goForward(void)
{
	TA1CCR1 = 0X0020;
	TA1CCTL1 = OUTMOD_3;

	TA1CCR2 = 0x0020;
	TA1CCTL2 = OUTMOD_3;
}
void goBackward(void)
{
	TA1CCR1 = 0X0020;
	TA1CCTL1 = OUTMOD_7;

	TA1CCR2 = 0x0020;
	TA1CCTL2 = OUTMOD_7;
}
void stopRobot(void)
{

}
