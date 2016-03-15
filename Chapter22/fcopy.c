// The following program makes a copy of a file. The names of the original file and
// the new file will be specified on the command line when the program is executed.
// For example, to copy the file f1.c to f2.c, we'd use the command
// fcopy f1.c f2.c
// fcopy will issue an error message if there aren't exactly two file names on the
// command line or if either file can't be opened. 

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	int ch;
	
	if (argc != 3) {
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}
	
	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}
	
	while((ch = getc(source_fp)) != EOF)
		putc(ch, dest_fp);
	
	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}

