// Modify the fcopy.c program of Section 22.4 so that it uses fread and fwrite to copy
// the file in blocks of 512 bytes. (The last block may contain fewer than 512 bytes, of course)

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main (int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	unsigned char buffer[BLOCK_SIZE];
	int read_number;
		
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
	
	while (read_number != EOF) {
	  read_number = fread(buffer, 1, BLOCK_SIZE, source_fp);
	  if (read_number == 0)
	  	break;
	  fwrite(buffer, 1, read_number, dest_fp);
  }
	
	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}
