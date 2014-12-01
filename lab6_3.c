#include <msp430.h>

void goForward(void);
void goBackward(void);
void stopMotor(void);
void turnRight(void);
void turnLeft(void);

void main(void) {
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    while(1)
    {
    goForward();
    _delay_cycles(1000000);
    stopMotor();
    _delay_cycles(1000000);
    goBackward();
    _delay_cycles(1000000);
    stopMotor();
    _delay_cycles(1000000);
    turnRight();
    _delay_cycles(1000000);
    stopMotor();
    _delay_cycles(1000000);
    turnLeft();
    _delay_cycles(1000000);
    stopMotor();
    _delay_cycles(1000000);
    }
} // end main

void goForward(void)
{
		P1DIR &= ~BIT3;
		P1REN |= BIT3;

		P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
	    P2SEL |= BIT2;							// Turns on L wheel

	    P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
	    P2SEL |= BIT4;							// Turns on R wheel

	    P2DIR |= BIT1;							// P2.2 is associated with TA1CCR2
	    P2OUT |= BIT1;							// OUT bc coming out of board... setting motor

	    P2DIR |= BIT3;							// P2.2 is associated with TA1CCR2
	    P2OUT |= BIT3;							// OUT bc coming out of board... setting motor

		TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	    TA1CCR0 = 0x0100;						// set signal period

	    TA1CCR1 = 0x0020;
	    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

	    TA1CCR2 = 0x0020;
	    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

}
void goBackward(void)
{
	P1DIR &= ~BIT3;
	P1REN |= BIT3;

		P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
	    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

	    P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
	    P2SEL |= BIT4;							// P2.2 is associated with TA1CCTL2

	    P2DIR |= (BIT1|BIT3);							// P2.2 is associated with TA1CCR2
	    P2OUT &= ~(BIT1|BIT3);							// OUT bc coming out of board... setting motor

	    TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	    TA1CCR0 = 0x0100;						// set signal period

	    TA1CCR1 = 0x0020;
	    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

	    TA1CCR2 = 0x0020;
	    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

}

void stopMotor(void)
{
	P1DIR &= ~BIT3;
	P1REN |= BIT3;

	P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
	P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

	P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.2 is associated with TA1CCTL2


	P2DIR = 0;
	P2OUT = 0;

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	TA1CCR0 = 0x0100;						// set signal period

	TA1CCR1 = 0x0020;
	TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

	TA1CCR2 = 0x0020;
	TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
}
void turnLeft(void)
{
	P1DIR &= ~BIT3;
	P1REN |= BIT3;

			P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
		    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

		    P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
		    P2SEL |= BIT4;							// P2.2 is associated with TA1CCTL2

		    P2DIR |= BIT1;							// P2.2 is associated with TA1CCR2
		    P2OUT |= BIT1;							// OUT bc coming out of board... setting motor

		    P2DIR &= ~BIT3;							// P2.2 is associated with TA1CCR2
		    P2OUT &= ~BIT3;							// OUT bc coming out of board... setting motor

		    TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
		    TA1CCR0 = 0x0100;						// set signal period

		    TA1CCR1 = 0x0020;
		    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

		    TA1CCR2 = 0x0020;
		    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
}
void turnRight(void)
{
	P1DIR &= ~BIT3;
	P1REN |= BIT3;

			P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
		    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

		    P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
		    P2SEL |= BIT4;							// P2.2 is associated with TA1CCTL2

		    P2DIR &= ~BIT1;							// P2.2 is associated with TA1CCR2
		    P2OUT &= ~BIT1;							// OUT bc coming out of board... setting motor

		    P2DIR |= BIT3;							// P2.2 is associated with TA1CCR2
		    P2OUT |= BIT3;							// OUT bc coming out of board... setting motor

		    TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
		    TA1CCR0 = 0x0100;						// set signal period

		    TA1CCR1 = 0x0020;
		    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

		    TA1CCR2 = 0x0020;
		    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode
}

