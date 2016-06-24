// Write the following function:
// char *max_pair(int num_pairs, ...);
// The arguments of max_pair are assume dto be "pairs" of integers and strings; the value of
// num_pairs indicates how many pairs will follow. (A pair consists of an int argument
// followed by a char * argument)/ The function searches the integers to find the largest one;
// it then returns the string argument that follows it. Consider the follwing call:
// max_pair(5, 180, "Seinfeld", 180, "I love Lucy", 
//              39, "The Honeymooners", 210, "All in the Family",
//              86, "The Sopranos")
// The largest int argument is 210, so the function returns "All in the Family", which
// follows it in the argument list. 

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *max_pair(int num_pairs, ...)
{
	va_list ap;
	int i, current, largest;
	char *str, *max_str;
	int str_len, max_len;
	
	va_start(ap, num_pairs);
	largest = va_arg(ap, int);
	max_str = va_arg(ap, char *);
	max_len = strlen(max_str);
	max_str = (char *) malloc(max_len + 1);
		
	//printf("first largest %d\n", largest);
	//printf("first str %s\n", max_str);
	
	for(i = 1; i < num_pairs; i++) {
		current = va_arg(ap, int);
		str = va_arg(ap, char *);
		
		if (current > largest) {
			largest = current;
			
			if ((str_len = strlen(str)) > (max_len = strlen(max_str)))
				max_str = (char *) realloc(max_str, str_len + 1);
			strcpy(max_str, str);
			
			//printf("current largest %d\n", largest);
			//printf("current str %s\n", max_str);
		}
	}
	
	va_end(ap);
	return max_str;
}

int main(void)
{
	printf("The result is \"%s\"\n", max_pair(5, 180, "Seinfeld", 180, "I love Lucy", 
					             539, "The Honeymooners", 210, "All in the Family",
					             86, "The Sopranos"));
	
	return 0;
}
