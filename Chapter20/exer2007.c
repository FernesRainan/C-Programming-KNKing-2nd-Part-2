#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE (sizeof(unsigned long)*4)

// Write the following functions:
unsigned long rotate_left(unsigned long i, int n);
unsigned long rotate_right(unsigned long i, int n);
// rotate_left should return the result of shifting the bits in i to the left by n places,
// with the bits that were "shifted off" moved to the right end of i. (For example, the call
// rotate_left(0x12345678, 4) should return 0x23456781 if integers are 32bits
// long.) rotate_right is similar, but it should "rotate" bits to the right instead of the left.

int main (void)
{
	unsigned long i
	int j;
	char s;
	
	printf("Enter a hexadecimal number (up to %d digits): 0x", sizeof(unsigned long));
	scanf("%x", &i);
	printf("The hexadecimal number is 0x%x.\n", i);
	
	getchar();            //dealing return value 
	
	printf("1.rotate_left?\n2.rotate_right?\n\nPlease select : ");
	 
	switch (s = getchar()) {
		case '1': 
			printf("How many bits do you want to shift off? ");
			scanf("%d", &j);
			printf("The result is 0x%x\n",rotate_left(i, j));
			break;
		case '2':
			printf("How many bits do you want to shift off? ");
			scanf("%d", &j);
			printf("The result is 0x%x\n",rotate_right(i, j));
			break;
		default:
			printf("Please select number 1 or 2\n?Please run the program again.\n");
			exit(EXIT_FAILURE);
	}
	
	return 0;
}

unsigned long rotate_left(unsigned long i, int n)
{
	
	return (i << n) | (i >> (BIT_SIZE - n));
}

unsigned long rotate_right(unsigned long i, int n)
{
	
	return (i >> n) | (i << (BIT_SIZE - n));
}
