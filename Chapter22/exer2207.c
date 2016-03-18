// Suppose that we call scanf as follows:
// n = scanf("%d%f%d", &i, &x, &j);
// (i, j, and n are int variables and x is a float variable.) Assuming that the input stream
// contains the characters shown, give the values of i, j, n, and x after the call. In addition,
// indicate which charcaters were consumed by the call. 

#include <stdio.h>

int main(void)
{
	int i, j, n;
	float x;
	
	printf("Quit for 'q' or enter: ");
	
	while(getchar() != 'q') {
		printf("Please enter three number: ");
		n = scanf("%d%f%d", &i, &x, &j);
		
		printf("The value of n, i, x and j are %d, %d, %f, %d\n\n", n, i, x, j);
		while (getchar() != '\n');
		printf("Quit for 'q' or enter: ");
		
	}
	printf("\nGoodbye!\n");
	
	return 0;
}

	
