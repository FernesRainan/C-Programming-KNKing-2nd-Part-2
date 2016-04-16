// Write a program named fcat that "concatenates" any number of files by writing them to
// standard output, one after the other, with no break between files. For example, the following
// command will display the files f1.c, f2.c and f3.c on the screen:
// fcat f1.c f2.c f3.c
// fcat should issue an error message if any file can't be opened. Hint: Since it has no more
// than one file open at a time, fcat needs only a single file pointer variable. Once it's 
// finished with a file, fcat can use the same variable when it opens the next file.

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	FILE *fp;
	int files;
	char ch;
	
	if (argc < 2) {
		fprintf(stderr, "usage: %s filename1 filename2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	for (files = 1; files < argc; files++) {  
		
		if ((fp = fopen(argv[files], "r")) == NULL) {
			fprintf(stderr,"%s can't be opened\n", argv[files]);
			exit(EXIT_FAILURE);
		}
		
		while ((ch = getc(fp)) != EOF)
			putchar(ch);
	
		fclose(fp);
	}
	
	return 0;
}
