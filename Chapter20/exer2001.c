// show the output produced by each of the following program fragments. Assume that i, j,
// and k are unsigned short variables. 

#include <stdio.h>

int main (void)
{
	unsigned short i, j, k;
	
	i = 8; j = 9;
	printf("a = %d\n", i >> 1 + j >> 1);
	printf("i >> 1 = %d\n", i >> 1);
	printf("j >> 1 = %d\n", j >> 1);
	printf("1 + j >> 1 = %d\n", 1 + j >> 1);
	
	i = 1;
	printf("b = %d\n", i & ~i);
	
	i = 2; j = 1; k = 0;
	printf("c = %d\n", ~i & j ^ k);
	
	i = 7; j = 8; k = 9;
	printf("d = %d\n", i ^ j & k);
	
	return 0;
}

