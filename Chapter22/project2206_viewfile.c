// Write a program that displays the contents of a file as bytes and as characters. Have the user
// specify the file name on the command line. Here's what the output will look like when the
// program is used to display the pun.c file of Section 2.1
//
// Each line shows 10 bytes from the file, as hexadecimal numbers and as characters. The
// number in the Offset column indicates the position within the file of the first byte on the
// line. Only printing characters (as determined by the isprint function) are displayed;
// other characters are shown as periods. Note that the appearance of a text file may vary,
// depending on the character set and the operating system. The example above assumes that
// pun.c is a Windows file, so 0D and 0A bytes (the ASCII carriage-return and line-feed
// characters) appear at the end of each line. Hint: Be sure to open the file in "rb" mode.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, n, offset;
	unsigned char buffer[10];
	
	if (argc != 2) {
		fprintf(stderr, "usage: viewfile file\n");
		exit(EXIT_FAILURE);
	}
	
	if ((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	printf("Offset              Bytes              Characters\n");
	printf("------  -----------------------------  ----------\n");
	
	for (offset = 0; ; offset += 10) {
		n = fread(buffer, 1, 10, fp);
		if (n == 0)
			break;
			
		printf("%6d  ", offset);
		for (i = 0; i < n; i++)
			printf("%.2X ", buffer[i]);
		for (; i < 10; i++)
			printf("   ");
		printf(" ");
		for (i = 0; i < n; i++) {
			if (!isprint(buffer[i]))
				buffer[i] = '.';
			printf("%c", buffer[i]);
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}


	
	
		
