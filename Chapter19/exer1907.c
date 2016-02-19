// Modify stackADT2.c so that a stack automatically doubles in size when it becomes full.
// Have the push function dynamically allocate a new array that's twice as large as the old
// one and then copy the stack contents from the old array to the new one. Be sure to have
// push deallocate the old array once the data has been copied. 

#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type {
	Item *contents;
	int top;
	int size;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(int size)
{
	Stack s = malloc(sizeof(struct stack_type));
	if(s == NULL)
		terminate("Error in create: stack could not be created.");
	s->contents = malloc(size * sizeof(Item));
	if (s->contents == NULL) {
		free(s);
		terminate("Error in create: stack could not be created.");
	}
	s->top = 0;
	s->size = size;
	return s;
}

void destroy(Stack s)
{
	free(s->contents);
	free(s);
}

void make_empty(Stack s)
{
	s->top = 0;
}

bool is_empty(Stack s)
{
	return s->top == 0;
}

bool is_full(Stack s)
{
	return s->top == s->size;
}

void push(Stack s, Item i)
{
	int j;
	
	if (is_full(s)){
		Stack temp1, temp2;
		temp1->contents = malloc(2 * (s->size) * sizeof(Item));
		
		if (temp1->contents == NULL) {
			free(temp1);
			terminate("Error in create: stack could not be created.");
		}
		temp1->top = 0;
		temp1->size = 2 * (s->size);
		s->top = 0;
		
		for (j = 0; j < (s->size)-1 ; j++)
			temp1->contents[temp1->top++] = s->contents[s->top++]; 
		temp1->contents[temp1->top] = s->contents[s->top];             //last elements copy 
		
		temp2 = s;
		s = temp1;
		free(temp2);
		
		s->contents[s->top++];                                         //pointing new top location
	}
		
	s->contents[s->top++] = i;
}

Item pop(Stack s)
{
	if (is_empty(s))
		terminate("Error in pop: stack is empty.");
	return s->contents[--s->top];
}

Item peek(const Stack s)
{
	if (is_empty(s))
		terminate("Error in pop: stack is empty.");
	Item value = s->contents[--s->top];
	s->contents[s->top++];
	
	return value;
}
