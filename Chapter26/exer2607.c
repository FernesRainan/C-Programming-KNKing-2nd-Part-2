// Explain the meaning of the following statement, assuming that value is a variable of type
// long int and p is a variable of type char *:
// value = strtol(p, &p, 10);

#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
	char *p = "2345343";
	long value;
	
	printf("String p is \"%s\"\n", p);
	
	value = strtol(p, &p, 10);
	
	printf("Long int value is %ld\n", value);
	printf("value * 2 is %ld\n", value * 2);
	
	return 0;
}


	
