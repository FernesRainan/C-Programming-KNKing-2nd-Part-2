// Write a function named display that takes any number of arguments. The first argument
// must be an integer. The remaining arguments will be strings. The first argument specifies
// how many strings the call contains. The function will print the strings on a single line, with
// adjacent strings separated by one space. For example, the call
// display(4, "Special", "Agent", "Dale", "Cooper");
// will produce the following output:
// Special Agent Dale Cooper

#include <stdarg.h>
#include <stdio.h>

void display(int count, ...)
{
  va_list ap;
  const char *p;
  int i;
  
  va_start(ap, count);

  for (i = 0; i < count; i++) {
    p = va_arg(ap, const char *);
    
    while (*p != '\0') 
      putchar(*p++);  
		putchar(' ');
	}
	va_end(ap);
	
	return ;
}

int main (void)
{
	display(4, "Special", "Agent", "Dale", "Cooper");
	
	putchar('\n');
	
	return 0;
}
