// Design a union that makes it possible to view a 32-bit value as either a float or the
// structure described in Exercise 14. Write a program that stores 1 in the structure's 
// sign field, 128 in the exponent field, and 0 in the fraction field, then prints the 
// float value stored in the union (The answer should be -2.0 if you've set up the bit-fields
// correctly.)

#include <stdio.h>

union view_bits {
	float fn;
	struct IEEE_float {
	unsigned int fraction: 23;
	unsigned int exponent: 8;
	unsigned int sign: 1;
	} ef;
};

int main(void)
{
	union view_bits i;
	
	i.ef.sign = 1;
	i.ef.fraction = 0;
	i.ef.exponent = 128;
	
	printf("%f\n", i.fn);
	
	return 0;
}

