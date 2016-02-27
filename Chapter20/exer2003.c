// Explain what effect the following macro has on its arguments. You may assume that the
// arguments have the same type.
// #define M(x,y) ((x)^=(y), (y)^=(x),(x)^=(y))

#include <stdio.h>
//#define M(x,y) ((x)^=(y), (y)^=(x),(x)^=(y))

int main (void)
{
	unsigned int i, j;
	
	printf("Enter the first integer: ");
	scanf("%d", &i);
	
	printf("Enter the second integer: ");
	scanf("%d", &j);
	
	(i)^=(j);
	(j)^=(i);
	(i)^=(j);
	
	printf("Now the first is %d, and the second is %d\n", i, j);
	
	return 0;
}

