// Write a call of memset that replaces the last n characters in a null-terminated string s with
// ! characters. 

#include <stdio.h>
#include <string.h>

int main(void) 
{
	char s[] = "Welcome to the new world!";
	int n = 5;
	
	memset(&s[strlen(s) - n], '!', n); // exer2311 
	
	printf("%s\n", s);
	
	return 0;
}
