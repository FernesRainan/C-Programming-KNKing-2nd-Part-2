// Write macros named GET_RED, GET_GREEN, and GET_BLUE that, when given a color as
// an argument (see Exercise 4), return its 8-bit red, green and blue intensities.

#include <stdio.h>

typedef unsigned int BYTE;

#define MK_COLOR(r,g,b) ((unsigned long) (b) << 16 | (g) << 8 | (r))

#define RED 0x0000ff
#define GREEN 0x00ff00
#define BLUE 0xff0000

#define GET_RED(color) ((BYTE) ((color) & RED))
#define GET_GREEN(color) ((BYTE) ((color) & GREEN) >> 8)
#define GET_BLUE(color) ((BYTE) ((color) & BLUE) >> 16)

int main (void)
{
	unsigned long color = MK_COLOR(34, 45, 100);
	
	printf("Red is 0x%.4X or %d\n", GET_RED(color),GET_RED(color));
	printf("Green is 0x%.4X or %d\n", GET_GREEN(color),GET_GREEN(color));
	printf("Blue is 0x%.4X or %d\n", GET_BLUE(color),GET_BLUE(color));
	
	return 0;
}

