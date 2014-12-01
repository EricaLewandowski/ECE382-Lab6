ECE382-Lab6
===========

#Prelab

[insert pictures from Prelab]

#Code Walk Through
NOTE: Use lab6-3.c for grading purposes. Because of the subtle differences in code, I started new files instead of 
trying to fix mine because CCS was acting up. 

Main called the different subroutines to move or stop the robot. The delay is in place so the viewer can detect the change
in motion and give the motor a chance to change movements without a harsh change. 

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

The individual subroutines create movement forward, stop, backwards, left or right. A sample of code is shown below. 

void turnRight(void)

{
		P1DIR &= ~BIT3;
		P1REN |= BIT3;

		P2DIR |= BIT2;							
		    P2SEL |= BIT2;							

		    P2DIR |= BIT4;							
		    P2SEL |= BIT4;							

		    P2DIR &= ~BIT1;							
		    P2OUT &= ~BIT1;							

		    P2DIR |= BIT3;							
		    P2OUT |= BIT3;							

		    TA1CTL = ID_3 | TASSEL_2 | MC_1;		
		    TA1CCR0 = 0x0100;						

		    TA1CCR1 = 0x0020;
		    TA1CCTL1 = OUTMOD_3;					

		    TA1CCR2 = 0x0020;
		    TA1CCTL2 = OUTMOD_7;					
}

#Debugging
NOTE: Use lab6-3.c for grading purposes. Because of the subtle differences in code, I started new files instead of 
trying to fix mine because CCS was acting up. 

#Observations/Conclusions
There's not quite enough time to do everything and understand what is going on. With Eric's help, I was finally able to
understand and toy with the code until it did what I wanted it to. 

#Documentation
C2C Eric Wardner helped me SO much. He explained which operators to use 
to get a specific direction, and then how to implement them. 
