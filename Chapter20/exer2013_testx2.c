// If n is an unsigned int variable, what effect does the following statement have on the
// bits in n?

// n &= n - 1;

// Hint: Consider the effect on n if this staement is executed more than once. 

#include <stdio.h>

int main(void)
{
	unsigned int n;
	
	printf("Please enter an integer: ");
	scanf("%d", &n);
	
	for (; n > 0 ; ){
		printf("n is %u and 0x%X.\n", n, n);
		n &= n - 1;
	}
	
	return 0;
}

	
