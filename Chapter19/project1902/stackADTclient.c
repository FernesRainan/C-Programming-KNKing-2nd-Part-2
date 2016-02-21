// Reverse Polish Notation (RPN) //

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
	Stack s1;
	char ch;
	int value;
	
	s1 = create();
	
	for (;;) {
		printf("Enter an RPN expression: ");
		
		for (;;) {
			
			scanf(" %1c", &ch);
			
			if (ch >= '0' && ch <= '9')
				push (s1, ((int) ch - '0'));
			else if (ch == '+')
				push (s1, (pop(s1) + pop(s1)));
			else if (ch == '-')
				subtract(s1);
			else if (ch == '*')
				push (s1, (pop(s1) * pop(s1)));
			else if (ch == '/')
				divide(s1);
			else break;
		}
		
		if (ch == '='){
			value = pop(s1);
			if (is_empty(s1)){ 
				printf("Value: %d\n", value);
			} 
			else {
				warn_incomplete();
				make_empty(s1);
			}
		}
		else {
			break;
		}
	}
	
	destroy(s1);
	
	return 0;
}


