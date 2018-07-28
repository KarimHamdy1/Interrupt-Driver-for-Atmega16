/*
 * InterruptFunction.c
 *
 * Created: 7/28/2018 04:39:44 م
 *  Author: User
 */ 

#include "InterruptFunction.h"


int interruptInit(char interruptNum,char intType)
{
	if(interruptNum >3 || interruptNum<0) // checking input parameters for appropriate settings.
	{
		return 0;
	}
	if( intType != 'r')
	{
		if(intType != 'f')
		{
			return 0;
		}
	}
	if(interruptNum == 0)
	{
		MCUCR |= 1<<ISC01 ;	/* Trigger INT0 on rising edge */
		if(intType == 'r')
		{
			MCUCR |=  1<<ISC00;
		}
		else if(intType == 'f')
		{
			MCUCR &=  0<<ISC00;	/* Trigger INT0 on Falling edge */
		}
		GICR |= 1<<INT0;		// enableing INT0
		sei();
		return 1;
	}else if(interruptNum == 1)
	{
		MCUCR |= 1<<ISC11 ;	/* Trigger INT1 on rising edge */
		if(intType == 'r')
		{
			MCUCR |=  1<<ISC10;
		}
		else if(intType == 'f')
		{
			MCUCR &=  0<<ISC10;	/* Trigger INT1 on Falling edge */
		}
		GICR |= 1<<INT1;					/* Enable INT1*/
		sei();
		return 1;
	}
	else if(interruptNum == 2)
	{
		if(intType == 'r')
		{
			MCUCSR |= 1<<ISC2;	/* Trigger INT2 on rising edge */
		}
		else if(intType == 'f')
		{
			MCUCSR &= 0<<ISC2;	/* Trigger INT2 on falling edge */
		}
		GICR |= 1<<INT2;					/* Enable INT2*/
		sei();
		return 1;
	}
}



ISR(INT0_vect)
{
	PORTC =~ PORTC;		/* Toggle PORTC */

}
ISR(INT1_vect)
{
	PORTC =~ PORTC;		/* Toggle PORTC */

}
ISR(INT2_vect)
{
	PORTC =~ PORTC;		/* Toggle PORTC */

}

