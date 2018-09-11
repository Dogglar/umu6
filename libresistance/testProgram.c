#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include "resistance.h"

float calc_resistance(int, char, float*);
float calc_parallel_resistans(int, float*);
float calc_serial_resistans(int, float*);

int main(int argc, char *argv[])
{
	float value = 0;
	int count = 6;
	float array[] = {100,200,600,3,666,100};

    printf("count=5, conn=P, array={100,200,600,3,666} : = ");
	value = calc_resistance(count, 'P', array);
	printf("%f\n", value);

	printf("count=5, conn=S, array={100,200,600,3,666} : = ");
	value = calc_resistance(count, 'S', array);
	printf("%f\n", value);

    printf("count=5, conn=P, array=(void *)0 : = ");
    value = calc_resistance(count, 'P', (void *)0);
	printf("%f\n", value);

    printf("count=5, conn=p, array={100,200,600,3,666} : = ");
    value = calc_resistance(count, 'p', array);
	printf("%f\n", value);

    printf("count=-1, conn=S, array={100,200,600,3,666} : = ");
	value = calc_resistance(-1, 'S', array);
    printf("%f\n", value);

    printf("count=5, conn=P, array={100,200,600,0,666} : = ");
    array[3] = 0;
	value = calc_resistance(count, 'P', array);
	printf("%f\n", value);


   return 0;
}





