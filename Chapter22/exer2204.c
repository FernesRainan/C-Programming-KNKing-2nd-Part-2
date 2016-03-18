// Show how each of the following numbers will look if displayed by printf with
// %#012.5g as the conversion specification

#include <stdio.h>

int main (void)
{
	printf("%#012.5g\n", 83.7361);
	printf("%#012.5g\n", 29748.6607);
	printf("%#012.5g\n", 1054932234.0);
	printf("%#012.5g\n", 0.0000235218);
	
	return 0;
}

