// Section 23.6 explains how to call strchr repeatedly to locate all occurrences of a character
// within a string. Is it possible to locate all occurrences in reverse order by calling
// strrchr repeatedly?

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *p = NULL, str[] = "find fund Form follows function.";
		
	p = strrchr(str, 'f');
	*p = 'A';
		
	printf("%s\n\n", str);
	
	while (p = strrchr(str , 'f')) {
		*p = 'a';
		printf("%s\n", str);
	}

	return 0;
}

