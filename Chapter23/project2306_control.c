// Write a program that copies a text file from standard input to standard output, replacing each
// control character (other than \n) by a question mark. 

// Replace the test condition in the following if statement by a single call of strchr:
// if (ch == 'a' || ch == 'b' || ch == 'c') ...
// char ch;
// if (strchr("abc", ch) != NULL)...
// char *p, str[] = "From follows function.";
// p = strchr(str, 'f'); // finds first 'f'
// p = strchr(p+1, 'f'); // finds next 'f'
// '\a' '\b' '\f' '\n' '\r' '\t' '\v' '\0' // control characters. 

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "This is the list of \'control characters\': \a \b \f \r \t \v \n" ;
	int i = 0;
			
	while (s[i] != '\n') {
		if (strchr("\a\b\f\r\t\v", s[i]) != NULL)
			s[i] = '?';
		i++;
	}
	
	printf("The result is: \n%s\n", s);
	
	return 0;
}

	
	
