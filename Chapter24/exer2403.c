// Modify the stackADT2.c file of Section 19.4 so that it uses assert to test for errors
// instead of using if statements (Note that the terminate function is no longer necessary
// and can be removed.)

// Implementing the Stack ADT Using a Fixed-Length Array
// The most striking thing about the functions in this file is that they use the -> 
// operator, not the . operator, to access the contents and top members of the 
// stack_type structure. The s parameter is a pointer to a stack_type structure
// not a structure itself, so using the . operator would be illegal. 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stackADT.h"

#define STACK_SIZE 100

struct stack_type {
	Item contents[STACK_SIZE];
	int top;
};

//static void terminate(const char *message)
//{
//	printf("%s\n", message);
//	exit(EXIT_FAILURE);
//}

Stack create(void)
{
	Stack s = malloc(sizeof(struct stack_type));
	
	assert(s != NULL);
	//if (s == NULL)
	//	terminate("Error in create: stack could not be created.");
	s->top = 0;
	return s;
}

void destroy(Stack s)
{
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
	return s->top == STACK_SIZE;
}

void push(Stack s, int i)
{
	bool IS_full = is_full(s);
	
	assert(IS_full != true);
//	if (is_full(s))
//		terminate("Error in push: stack is full.");
	s->contents[s->top++] = i;
}

int pop(Stack s)
{
	bool IS_empty = is_empty(s);
	
	assert(IS_empty != true);
//	if (is_empty(s))
//		terminate("Error in pop: stack is empty.");
	return s->contents[--s->top];
}

