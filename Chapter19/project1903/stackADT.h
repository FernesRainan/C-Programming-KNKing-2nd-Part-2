// Changing the Item Type in the Stack ADT
// To make the stack ADT easier to modify for differenct item types, let's add a
// type definition to the stackADT.h header. It will define a type named Item, 
// representing the type of data to be stored on the stack. 

// Modify the stackADT3.c file of Section 19.4 by adding an int member named len to
// the stack_type structure. This member will keep track of how many items are currently
// stored in a stack. Add a new function named length that has a Stack parameter and
// returns the value of the len member. (Some of the existing functions in stackADT3.c
// will need to be modified as well). Modify stackclient.c so that it calls the length
// function (and displays the value that it returns) after each operation that modifies a stack. 


#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef int Item;

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
int length(Stack s);

#endif



