// Extend the function of Exercise 2 so that it allows two conversion specifications: %d and
// %s. Each %d in the format string indicates an int argument, and each %s indicates a char 
// * (string) argument.

#include <stdarg.h>
#include <stdio.h>

void ext_printf(const char *format, ...)
{
  va_list ap;
  const char *p;
  char *s;
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
    } else if (*p == 's') {     
      s = va_arg(ap, char *);   // Caution!! : the condition is NOT *++p == 's', side effect! 
      
      for(; *s != '\0'; s++) 
      	putchar(*s);
    }
    
  }
  va_end(ap);
}

int main (void)
{
	int i = 34500;
	char* ch1 = "Test Sentence1";
	char* ch2 = "Test Sentence2";
	
	//printf("%s\n", ch);
	ext_printf("This is test of int_printf: value ch1 = %s i = %d ch2 = %s", ch1, i, ch2);
	
	return 0;
}
