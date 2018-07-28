/*
 * InterruptFunction.h
 *
 * Created: 7/28/2018 04:39:11 م
 *  Author: User
 */ 


#ifndef INTERRUPTFUNCTION_H_
#define INTERRUPTFUNCTION_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

/* The function initiates the interrupt register for the assigned INT vector.
Available interrupt numbers : 0,1,2.
Available Types : Rising edge --> intType = 'r'
				  Falling edge --> intType = 'f'
The function returns 1 on successful initiation, Returns 0 on incorrect input parameters.
*/
int interruptInit(char interruptNum,char intType);


ISR(INT0_vect);
ISR(INT1_vect);
ISR(INT2_vect);


#endif /* INTERRUPTFUNCTION_H_ */