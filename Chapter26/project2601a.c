// Write a program that calls the rand function 1000 times, printing the low-order bit of
// each value it returns (0 if the return value is even, 1 if it's odd). Do you see any patterns?
// (Often, the last few bits of rand's return value aren't especially random.)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count = 1000;
	
	while (count-- > 0)
		printf("%d", rand() & 1);
	printf("\n");
	return 0;
}
