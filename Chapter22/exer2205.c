// Is there any difference between the printf conversion specifications %.4d and %04d? 
// If so, explain what it is. 

#include <stdio.h>

int main(void)
{
	
	printf("%.4d\t%04d\n", -123456, -123456);
	printf("%.4d\t%04d\n", -456, -456);
	printf("%.4d\t%04d\n", -1234, -1234);
	
	return 0;
}
