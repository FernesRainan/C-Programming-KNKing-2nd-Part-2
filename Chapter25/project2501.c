// Write a program that tests whether your compiler's "" (native) locale is the same as its "C"
// locale.

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *temp, *C_locale;
	
	temp = setlocale(LC_ALL, NULL); // "C" is the current locale by default
	if(temp == NULL) {
		printf("\"C\" locale information not available\n");
		exit(EXIT_FAILURE);
	}
	
	C_locale = malloc(strlen(temp) + 1);
	if (C_locale == NULL) {
		printf("Can't allocate space to store locale information\n");
		exit(EXIT_FAILURE);
	}
	
	strcpy(C_locale, temp);
	
	temp = setlocale(LC_ALL, "");
	if(temp == NULL) {
		printf("Native locale information not available\n");
		exit(EXIT_FAILURE);
	}
	
	if (strcmp(temp, C_locale) == 0)
		printf("Native locale is the same as the \"C\" locale\n");
	else
		printf("Native locale is not the same as the \"C\" locale\n");
	
	return 0;
}

	
