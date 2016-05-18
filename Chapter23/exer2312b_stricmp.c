// Many versions of <string.h> provide additional (nonstandard) functions, such as those
// listed below. Write each finction using only the features of the C standard.

// stricmp(s1, s2) -- Similar to strcmp, but ignores the case of letters.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* strdup(const char* s) {
	int len = strlen(s) + 1;
	void *dest = malloc (len);
	
	if(dest == NULL)
		return NULL;
		
	return (char *) memcpy (dest, s, len);
}

int stricmp (const char *s1, const char *s2)
{
	char *temp1, *temp2;
	int result;
	char *add1, *add2;
	
	temp1 = strdup(s1);
	temp2 = strdup(s2);
		
	for (add1 = temp1 ; *add1 != '\0'; add1++)
		*add1 = toupper(*add1);
	for (add2 = temp2 ; *add2 != '\0'; add2++)
		*add2 = toupper(*add2);
		
	result = strcmp (temp1, temp2);
	
	free(temp1);
	free(temp2);
	
	return result;
}

int main(void)
{
	char s1[]="welcome to the new world!";
	char s2[]="WELCOME TO the new world!";
	
	printf("s1 is %s\ns2 is %s\n\n", s1, s2);
	printf("The stricmp result is %d\n", stricmp (s1, s2));
	printf("The strcmp result is %d\n", strcmp (s1, s2));
	
	return 0;
}
