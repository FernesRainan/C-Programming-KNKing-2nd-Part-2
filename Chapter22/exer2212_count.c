#include <stdio.h>
#include <stdlib.h>

// Find the error in the following function and show how to fix it.

int count_periods(const char *filename)
{
	FILE *fp;
	int n = 0;
	char ch;                                      // fix, add variable
	
	if ((fp = fopen(filename, "r")) != NULL) {
		while ((ch = fgetc(fp)) != EOF)             // fix, storing value
			if ( ch == '.')                           // fix, comparing value, not using fgetc  
				n++;
		fclose(fp);
	}
	
	return n;
}

int main (int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	printf("Counting number is %d\n", count_periods(argv[1]));
	
	return 0;
}

