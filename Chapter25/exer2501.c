// Determine which locales are supported by our compiler. 

// 'locale -a' displays available locales. 
// 'locale' displays environmental variables that impact how locale("") will be deduced. 

// Below code is to get current locale of the environment.

#include <stdio.h>
#include <locale.h>

int main (void)
{
	setlocale(LC_ALL, "");
	printf("LC_ALL: %s\n", setlocale(LC_ALL, NULL));
	printf("LC_CTYPE: %s\n", setlocale(LC_CTYPE, NULL));
	
	return 0;
}
