// Rewrite the max_int function so that, instead of passing the number of integers as the first
// argument, we must supply 0 as the last argument, Hint: max_int must have at least one
// "normal" parameter, so you can't remove the parameter n. Instead, assume that it represents
// one of the numbers to be compared. 

#include <stdarg.h>
#include <stdio.h>

int max_int(int n, ...)
{
	va_list ap;
	int i, current, largest;
	
	va_start(ap, n);
	largest = va_arg(ap, int);
	
	while (n != (current = va_arg(ap, int))) 
		if (current > largest)
			largest = current;
	
	va_end(ap);
	return largest;
}

int main(void)
{
	printf("The largest number is %d\n", max_int(0, 10, 30, 20, 50, 219, 34, 2, 0));
	
	return 0;
}
