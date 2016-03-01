#include <stdio.h>

// The following function supposedly combines two bytes to form an unsigned short integer. 
// Explain why the function doesn't work and show how to fix it. 

// unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
// {
// 	return high_byte << 8 + low_byte;
// }

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
	return (unsigned short) high_byte << 8 | (unsigned short) low_byte;
}

int main(void)
{
	unsigned char h = 1, l = 2;
	
	printf("unsigned short high byte = %hd, low byte = %hd.\n", (unsigned short) h, (unsigned short) l);
	
	printf("combined result is %hd and 0x%hx.\n", create_short(h,l),create_short(h,l));
	
	return 0;
}

	
	
