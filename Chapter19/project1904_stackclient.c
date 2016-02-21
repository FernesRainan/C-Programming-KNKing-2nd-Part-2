// The following client file can be used to test the stack ADT. 
// It creates two stacks and performs a variety of operations on them. 

// Modify the stackADT.h and stackADT3.c files of Section 19.4 so that a stack stores
// values of type void *, as described in Section 19.5; the Item type will no longer be used. 
// Modify stackclient.c so that it stores pointers to strings in the s1 and s2 stacks. 

#include <stdio.h>
#include "stackADT.h"

int main(void)
{
	Stack s1, s2;
	void *n;
	
	s1 = create();
	s2 = create();
	
	push(s1, "\"first\"");
	push(s1, "\"second\"");
	
	n = pop(s1);
	printf("Popped %s from s1\n", n);
	push(s2, n);
	n = pop(s1);
	printf("Popped %s from s1\n", n);
	push(s2, n);
	
	destroy(s1);
	
	while (!is_empty(s2))
		printf("Popped %s from s2\n", pop(s2));
		
	push(s2, "\"third\"");
	make_empty(s2);
	if(is_empty(s2))
		printf("s2 is empty\n");
	else
		printf("s2 is not empty\n");
	
	destroy(s2);
	
	return 0;
}

