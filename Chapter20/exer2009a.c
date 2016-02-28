#include <stdio.h>

// (a) Write the following function:
int count_ones(unsigned char ch);
// count_ones should return the number of 1 bits in ch. 

int main (void)
{
	char ch;
	
	printf("Enter an character: ");
	scanf(" %c", &ch);
	
	printf("This character '%c' is %d.\n", ch, ch);
	printf("This character '%c' has %d ones in bits\n", ch, count_ones(ch));
	
	return 0;
}

int count_ones(unsigned char ch)
{
	int count = 1;
	
	while (ch > 1) {
		count += ((int)ch % 2);
		ch /= 2;
	}
	
	return count;
}
