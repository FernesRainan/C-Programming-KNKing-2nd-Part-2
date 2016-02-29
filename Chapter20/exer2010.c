#include <stdio.h>

// Write the following function:
unsigned int reverse_bits (unsigned int n);
// reverse_bits should return an unsigned integer whose bits are the same as 
// those in n but in reverse order.

int main (void)
{
	unsigned int i;
	
	printf("Enter an integaer: ");
	scanf("%u", &i);
	
	printf("The reverse bits result is %u\n", reverse_bits(i));
	 
	return 0;
}

unsigned int reverse_bits(unsigned int i)
{
	unsigned int j = 0;
	unsigned int binary;
	int count;
	
	for (count = 0; count < 32 ; count++) {
		binary = (i >> count) & 1;
		j |= (binary << (31-count));
	}	
	
	return j;	
}
