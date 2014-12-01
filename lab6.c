#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    P1DIR &= ~BIT3;
    P1REN |= BIT3;

    P2DIR |= BIT0;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT0;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT1;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT1;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT3;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT3;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.2 is associated with TA1CCTL2

    P2DIR |= BIT5;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT5;							// P2.2 is associated with TA1CCTL1

    TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    TA1CCR1 = 0x0020;
    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

    while (1) {

    	while((P1IN & BIT3) != 0);			// Wait for a button press
    	while((P1IN & BIT3) == 0);			// and release

        TA1CCR1 = (TA1CCR1 + 0x010) & 0xFF;	// increase duty cycle
        TA1CCR2 = (TA1CCR2 + 0x010) & 0xFF;	// decrease duty cycle

    } // end loop
} // end main
