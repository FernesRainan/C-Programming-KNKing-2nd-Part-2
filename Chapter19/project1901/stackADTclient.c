// Modify Programming Project 1 from Chapter 10 so that it uses the stack ADT described in
// Section 19.4. You may use any of the implementations of the ADT described in that section. 

#include <stdbool.h>
#include <stdio.h>
#include "stackADT.h"

int main (void)
{
	Stack s1;
	char i;
	
	s1 = create();
	
	printf("Enter parentheses and/or braces: ");
	
	while ((i = getchar()) != '\n'){
		switch (i) {
			case '(': case '{':
				push(s1, i); 
				break;
			case ')':
				if (is_empty(s1) || pop(s1) != '(')
					not_nested(); 
					break;
			case '}':
				if (is_empty(s1) || pop(s1) != '{')
					not_nested(); 
					break;
		}
	}
	
	if (is_empty(s1))
		nested();
	else 
		not_nested();
	
	destroy(s1);
		
	return 0;
}
