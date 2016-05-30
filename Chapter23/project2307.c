// Write a program that counts the number of sentences in a text file (obtained from standard 
// input). Assume that each sentence ends with a .,?, or ! followed by a white-space character
// (including \n).

// int isspace (int c)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	char s[] = "One sent\tence!and Two s\ventences? Three sentences.\n";
	bool is_end = false;
	int i, count = 0;
		
	for (i = 0; i < strlen(s) ; i++) {
		if (strchr(".?!", s[i])) {
			is_end = true;
			i++;
		}
		
		if (isspace(s[i]) && (is_end == true)) {
			count++;
			is_end = false;
		} else if (!isspace(s[i]) && (is_end == true)) 
			is_end = false;
	}
	
	printf("The sentence is \'%s\'\n", s);
	printf("The number of sentences is %d\n", count);
	
	return 0;
}


		
	 
	
	
	
