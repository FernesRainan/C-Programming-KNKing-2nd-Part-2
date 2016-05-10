// Using isxdigit, write a function that checks whether a string represents a valid hexadecimal
// number (it consists solely of hexadecimal digits). If so, the function returns the value of
// the number as a long int. Otherwise, the function returns -1. 

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SYSTEM 16

long int check_hex(char* str)
{
	char *ptr;
	long int result = 0;

	for (ptr = str ; *ptr != '\0'; ptr++) {          
		if (isxdigit(*ptr))
			continue;
		else
			return -1;
	}	
// ((...((a(n)x+a(n-1))x + a(n-2))x +...)x + a(1))x + a(0)
// Use the fma function to perform the multiplication and additions.
	for (ptr = str ; *ptr != '\0'; ptr++ ) {
		if (*ptr >= 'a' && *ptr <= 'f')
			result = fma(result, SYSTEM, ((*ptr - 'a') + 10));
		else if (*ptr >= 'A' && *ptr <= 'F')	
			result = fma(result, SYSTEM, ((*ptr - 'A') + 10));
		else
			result = fma(result, SYSTEM, (*ptr - '0'));
	}
		// Character to number
	
	return result;
	
}	

int main()
{
	long int check;
			
	char var1[] = "123t";
	char var2[] = "1Ae4";
  
  check = check_hex(var1);
  
  if( check == -1 )
  	printf("\"%s\" is not hexadecimal digit.\n", var1);
  else
  	printf("\"%s\" is hexadecimal digit, and value is %ld.\n", var1, check);
  
  check = check_hex(var2);
  
  if( check == -1 )
  	printf("\"%s\" is not hexadecimal digit.\n", var2);
  else
  	printf("\"%s\" is hexadecimal digit, and value is %ld.\n", var2, check);	
   
  return 0;
}
