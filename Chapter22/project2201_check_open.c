// Extend the canopen.c program of Section 22.2 so that the user may put any number of
// file names on the command line:
// canopen foo bar baz
// The program should print a separate can be opened or can't be opened message for
// each file. Have the program terminate with status EXIT_FAILURE if one or more of the
// files can't be opened. 

#include <stdio.h>
#include <stdlib.h>
typedef enum { false, true } bool;

int main (int argc, char *argv[])
{
	FILE *fp;
	int files;
	bool fail_flag = false;
	
	if (argc < 2) {
		printf("usage: canopen filename1 filename2 ...\n");
		exit(EXIT_FAILURE);
	}
	
	for (files = 1; files < argc; files++) {  
		
		if ((fp = fopen(argv[files], "r")) == NULL) {
			printf("%s can't be opened\n", argv[files]);
			fail_flag = true;
		}
		else
			printf("%s can be opened\n", argv[files]);
			
		fclose(fp);
	}
	
	if (fail_flag)
		exit(EXIT_FAILURE);
	else
		return 0;
}
