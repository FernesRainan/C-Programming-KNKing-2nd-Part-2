// (b) Write the function in part(a) without using a loop.

#include <stdio.h>

void show_binary(unsigned char n);
int count_ones(unsigned char ch);

int main (void)
{
	char ch;
	
	printf("Enter an character: ");
	scanf(" %c", &ch);
	
	printf("This character '%c' is %d and ", ch, ch);
	show_binary(ch);
	printf("This character '%c' has %d ones in bits\n", ch, count_ones(ch));
	
	return 0;
}

void show_binary(unsigned char n)
{
	while (n) {
	    if (n & 1)
	        printf("1");
	    else
	        printf("0");
	
	    n >>= 1;
	}
	printf(" <== reverse \n");
	return ;	
}

int count_ones(unsigned char ch)
{
		return ((ch>>7) & (0x1)) + ((ch>>6) & (0x1)) + ((ch>>5) & (0x1)) +
		((ch>>4) & (0x1)) + ((ch>>3) & (0x1)) + ((ch>>2) & (0x1)) +
		((ch>>1) & (0x1)) + ((ch) & (0x1));
}
