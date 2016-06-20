// Write s simplified version of printf in which the only conversion specification is %d, and
// all arguments after the first are assumed to have int type. If the function encounters a %
// character that's not immediately followed by a d character, it should ignore both characters. 
// The function should use calls of putchar to produce all output. You may assume that the
// format string doesn't contain escape sequences. 

#include <stdarg.h>
#include <stdio.h>

void int_printf(const char *format, ...)
{
  va_list ap;
  const char *p;
  int digit, i, power, temp;

  va_start(ap, format);

  for (p = format; *p != '\0'; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    if (*++p == 'd') {
      i = va_arg(ap, int);
      if (i < 0) {
        i = -i;
        putchar('-');
      }

      temp = i;
      power = 1;
      while (temp > 9) {
        temp /= 10;
        power *= 10;
      }
			
      do {
        digit = i / power;
        putchar(digit + '0');
        i -= digit * power;
        power /= 10;
   		} while (i > 0);
    	
    	while (power >= 1) {			// Adding these lines to original answer of website. 
    		putchar('0');           // Because, original output of '1030' is '103' or '100' is '1'
    		power /= 10;            // the remained '0' characters are missing. 
    	}                         // So this part corrects the flaw.  
    	
    }
  }

  va_end(ap);
}
int main (void)
{
	int i, j;
	i = 1300; j = 1540;
	
	int_printf("This is test of int_printf: value i = %d j = %d", i, j);
	
	return 0;
}
