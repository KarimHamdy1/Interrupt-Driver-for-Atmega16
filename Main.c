
#include "InterruptFunction.h"

int main(void)
{
	DDRC = 0xff;
	DDRD = 0b11110000;
	PORTC =0x00;
	DDRA = 0xff;
	int a;
	interruptInit(0,'r');
	interruptInit(2,'f');

		
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
