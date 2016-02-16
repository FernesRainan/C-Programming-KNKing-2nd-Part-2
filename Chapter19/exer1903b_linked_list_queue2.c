// Write a linked-list implementation of the queue module described in Exercise 1.
// Use two pointers, one pointing to the first node in the list and the other
// pointing to the last node. When an item is inserted into the queue, add it
// to the end of the list. When an item is removed from the queue, delete the first
// node in the list. 

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
	int data;
	struct node *next;
};

static struct node *front = NULL;
static struct node *rear = NULL;

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

bool is_empty(void)
{
	return front == NULL;
}

void insert(int i)
{
	if (rear == NULL) {
		rear = (struct node *)malloc(sizeof(struct node));
		rear->next = NULL;
		rear->data = i;
		front = rear;
	} 
	else {
		struct node *new_node = malloc(sizeof(struct node));
		if (new_node == NULL)
			terminate("Error in insert: queue is full.");
		
		rear->next = new_node;
		new_node->data = i;
		new_node->next = NULL;
		
		rear = new_node;
	}
}

int qremove(void) 
{
	struct node *old_front;
	int value;
	
	if (is_empty())
		terminate("Error in qremove: queue is empty.");
	
	old_front = front;
	
	if (old_front->next != NULL){
		front = front->next;
		value = old_front->data;
		free(old_front);
	} 
	else {
		value = front->data;
		free(front);
		front = NULL;
		rear = NULL;
	}
	
	return value;
}
 
int first(void)
{
	if (is_empty())
		terminate("Error in qremove: queue is empty.");
	
	return front->data;
}

int last(void)
{
	if (is_empty())
		terminate("Error in qremove: queue is empty.");
	
	return rear->data;
}

