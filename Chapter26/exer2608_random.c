// Write a statement that randomly assigns one of the numbers 7, 11, 15, or 19 to the variable n.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	int i[4] = {7, 11, 15, 19};
	int n, seed;
	
	printf("This program randomly assigns one of the numbers 7, 11, 15 or 19\n");
	
	for (;;) {
		srand(time(NULL));
		n = i[rand() % 4];
		printf("n is %d\n\n", n);
		printf("Enter 0 to terminate: ");
		scanf("%d", &seed);
		if (seed == 0)
			break;
	}
	
	return 0;
}

