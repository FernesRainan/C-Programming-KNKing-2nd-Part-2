// Many versions of <string.h> provide additional (nonstandard) functions, such as those
// listed below. Write each finction using only the features of the C standard.

// strset(s, ch) -- Fills s with copies of the character ch; returns s.

#include <stdio.h>
#include <ctype.h>

char* strset(char* s, char ch)
{
	char* add;
	
	for (add = s ; *add != '\0'; add++)
		*add = ch;

	return s;
}

int main(void)
{
	char s[] = "Welcome to THE NEW WORLD!";
	char ch = 'A';
	printf("The original  is \"%s\"\n", s);
	printf("The converted is \"%s\"\n", strset(s, ch));
	
	return 0;
}
