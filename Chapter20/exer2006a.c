#include <stdio.h>

// (a) Use the bitwise operators to write the following function:
unsigned short swap_bytes(unsigned short i);
// swap_bytes should return the number that results from swapping the two bytes in i.
// (Short integers occupy two bytes on most computers.) For example, if i has the value
// 0x1234 (00010010 00110100 in binary), then swap_bytes should return 0x3412
// (00110100 00010010 in binary). Test your function by writing a program that reads a number
// in hexadecimal, then writes the number with its bytes swapped:

// Enter a hexadecimal number (up to four digits) : 1234
// Number with bytes swapped: 3412
// Hint: Use the %hx conversion to read and write the hex numbers.

int main (void)
{
	unsigned short i;
	
	printf("Enter a hexadecimal number (up to four digits): ");
	scanf("%hx", &i);
	printf("Number with bytes swapped: %hx\n", swap_bytes(i));
	return 0;
}

unsigned short swap_bytes(unsigned short i)
{
	unsigned short high_byte = i << 8;
	unsigned short low_byte = i >> 8;
	
	return high_byte | low_byte;
}

