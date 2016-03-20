// Write the following function:
// int line_length(const char *filename, int n);
// The function should return the length of line n in the text file whose name is filename 
// (assuming that the first line in the file is line 1). If the line doesn't exist, the function
// should return 0.

#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n)
{
	FILE *fp;
	int count = 0, line = 1;
	char ch;                                      
	
	if ((fp = fopen(filename, "r")) != NULL) {
		while ((ch = fgetc(fp)) != EOF){	
			if (line == n && ch != '\n') 
				count++;
			if (ch == '\n') 
				line++;	
		}
		
		fclose(fp);
	}
	
	return (count - 1);           // "if condition" modifying
}

int main (int argc, char *argv[])
{
	int line, result;
	
	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	printf("Which line should be counted? : ");
	scanf("%d", &line);
	
	result = line_length(argv[1], line);
	
	if (result >= 0)
		printf("\"%s\" %d line length is %d\n", argv[1], line, result);
	else
		printf("\n%d line is out of \"%s\".\nTry again.\n", line, argv[1]);
	
	return 0;
}

