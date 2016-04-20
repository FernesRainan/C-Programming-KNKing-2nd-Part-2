// The xor.c program of Section 20.1 refuses to encrypt bytes that - in original or encrypted
// form - are control characters. We can now remove this restriction. Modify the program so
// that the names of the input and output files are command-line arguments. Open both files in
// binary mode, and remove the test that checks whether the original and encrypted charcaters
// are printing characters. 

// Performs XOR encryption

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int orig_char;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if ((fp1 = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if ((fp2 = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't write %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while ((orig_char = getc(fp1)) != EOF)
		putc(orig_char ^ KEY, fp2);
	
	fclose (fp1);
	fclose (fp2);
	
	return 0;
}
