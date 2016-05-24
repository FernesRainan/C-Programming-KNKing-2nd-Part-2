// Write a program that copies a text file from standard input to standard output, removing all
// white-space characters from the beginning of each line. A line consisting entirely of white-
// space characters will not be copied. 

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main (void)
{
	bool nonblank_seen = false;
	int ch;
	
	while ((ch = getchar()) != EOF) {
		if (nonblank_seen)
			putchar(ch);
		else if (!isspace(ch)) {
			nonblank_seen = true;
			putchar(ch);
		}
		if (ch = '\n') {
			nonblank_seen = false;
		}
	}
	
	return 0;
}

