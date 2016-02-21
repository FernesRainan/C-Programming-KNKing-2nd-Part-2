// Changing the Item Type in the Stack ADT
// To make the stack ADT easier to modify for differenct item types, let's add a
// type definition to the stackADT.h header. It will define a type named Item, 
// representing the type of data to be stored on the stack. 

#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef int Item;

typedef struct stack_type *Stack;

static void terminate(const char *message);
Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
void warn_incomplete (void);
void subtract(Stack s);
void divide (Stack s);


#endif



