// Many versions of <string.h> provide additional (nonstandard) functions, such as those
// listed below. Write each finction using only the features of the C standard.

// strdup (s) -- Returns a pointer to a copy of s stored in memory obtained by calling
// malloc. Returns a null pointer if enouh memory couldn't be allocated. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strdup(const char* s) 
{
	int len = strlen(s) + 1;
	void *dest = malloc (len);
	
	if(dest == NULL)
		return NULL;
		
	return (char *) memcpy (dest, s, len);
}

int main(void)
{
	char *backup, s[] = "Welcome to the new world!";
	
	backup = strdup(s);
	
	printf("Backup is %s\nOriginal is %s\n", backup, s);
	
	free(backup);
	
	return 0;
}

	
