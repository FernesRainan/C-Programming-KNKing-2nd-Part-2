// Write a function that returns a random double value d in the range 0.0 <= d < 1.0

#include <stdio.h>
#include <stdlib.h>

double rand_double(void)
{
	return (double) rand() / (RAND_MAX + 1);
}

int main(void)
{
	int seed;
	
	printf("This program returns a random double value d in the range 0.0 <= d < 1.0\n");
	
	for (;;) {
		printf("d is %f\n\n", -(rand_double()));
		printf("Enter 0 to terminate: ");
		scanf("%d", &seed);
		if (seed == 0)
			break;
	}
	
	return 0;
}
