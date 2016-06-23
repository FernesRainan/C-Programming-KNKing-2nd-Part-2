// Write the following function:
// char *vstrcat(const char *first, ...);
// All arguments of vstrcat are assumed to be strings, except for the last argument, which
// must be a null pointer(cast to char * type). The function returns a pointer to a dynamically
// allocated string containing the concatenation of the arguments. vstrcat should return a
// null pointer if not enough memory is available. Hint: Have vstrcat go through the argu-
// ments twice: once to determine the amount of memory required for the returned string and
// once to copy te arguments into the string. 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char *vstrcat(char *first, ...)
{
	int len = 0;
	char *dest, *p;
	va_list ap;
	
	if(first == NULL)
		return NULL;

	len = strlen(first);

	va_start(ap, first);

	while((p = va_arg(ap, char *)) != NULL)
		len += strlen(p);

	va_end(ap);

	dest = (char *) malloc(len + 1);	/* +1 for trailing \0 */

	if(dest == NULL)
		return NULL;		/* error */

	strcpy(dest, first);

	va_start(ap, first);

	while((p = va_arg(ap, char *)) != NULL)
		strcat(dest, p);
		
	va_end(ap);
		
	return dest;
}


int main (void)
{
	char *str = vstrcat("This ", "is ", "exercise ", "Test.", (char *) NULL);

	puts(str);

	return 0;
}
