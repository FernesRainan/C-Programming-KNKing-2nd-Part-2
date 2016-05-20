// Many versions of <string.h> provide additional (nonstandard) functions, such as those
// listed below. Write each finction using only the features of the C standard.

// strrev(s) -- Reverses the characters in s (except the null character); returns s.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strdup(const char* s) 
{
	int len = strlen(s) + 1;
	void *dest = malloc (len);
	
	if(dest == NULL)
		return NULL;
		
	return (char *) memcpy (dest, s, len);
}

char* strrev(char* s)
{
	char* temp;
	int i, len = strlen(s);
	// printf("strlen is %d\n", len);
	
	temp = strdup(s);  // creates dummy
	
	for (i = 0; i < len; i++)   // reverse 
		temp[i] = s[len - i - 1]; // '\0' excluded
		
	for (i = 0; i < len; i++)   // copy 'reverse' to original array
		s[i] = temp[i];
	
	free(temp);
	
	return s;
}

int main(void)
{
	char s[] = "0123456789";
	
	printf("Original is %s\n", s);
	printf("The converted is %s\n", strrev(s));
	
	return 0;
}

