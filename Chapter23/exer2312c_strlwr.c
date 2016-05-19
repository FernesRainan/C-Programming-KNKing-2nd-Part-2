// Many versions of <string.h> provide additional (nonstandard) functions, such as those
// listed below. Write each finction using only the features of the C standard.

// strlwr(s) -- Converts upper-case letters in s to lower case, leaving other characters
// unchanged; returns s.

#include <stdio.h>
#include <ctype.h>

char* strlwr(char* s)
{
	char* add;
	
	for (add = s ; *add != '\0'; add++)
		*add = tolower(*add);

	return s;
}

int main(void)
{
	char s[] = "Welcome to THE NEW WORLD!";
	
	printf("Original is \"%s\"\n", s);
	printf("The converted is \"%s\"\n", strlwr(s));
	
	return 0;
}

	
