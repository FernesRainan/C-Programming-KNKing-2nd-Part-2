// Write a program that copies a text file from standard input to standard ouput, capitalizing
// the first letter in each word. 

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main (void)
{
	bool blank = true;
	int ch;
	
	printf("Please enter any string, and to quit, press CTRL+C\n");
	
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\t') {
			blank = true;
			putchar(ch);
		} else if (blank == true && isalpha(ch)) {
			putchar(toupper(ch));
			blank = false;
		} else  
			putchar(ch);
	}
	
	return 0;
}


		