// Write a call of assert that causes a program to terminate if a variable named top has the
// value NULL

#include <stdio.h>
#include <assert.h>

int main (void)
{
	int *top;
	
	top = NULL;
	
	assert(top != NULL); // call of assert
	
	printf("The program terminated normally.\n");
	
	return 0;
}
