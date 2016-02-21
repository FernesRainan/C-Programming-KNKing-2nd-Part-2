// Modify Programming Project 5 so that the items in a queue are stored in a linked list 
// (See Exercise 3(b)

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
	Item data;
	struct node *next;
};

struct queue_type {
	struct node *rear;                 // Item storing the position of the first empty slot         
	struct node *front;                // Item storing the position of the next item to be removed.
	int count;                         // Item storing the number of items in the queue.           
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created.");
	q->rear = NULL;
	q->front = NULL;
	q->count = 0;
	return q;
}

void destroy(Queue q)
{
	make_empty(q);
	free(q);
}

void make_empty(Queue q)
{
	while(!is_empty(q))
		qremove(q);
}
	
bool is_empty(Queue q)
{
	return q->front == NULL;
}

void insert(Queue q, Item i)
{
	if (q->front == NULL){
		q->front = (struct node *)malloc(sizeof(struct node));
		if (q->front == NULL)
			terminate("Error in insert: queue is full.");
			
		(q->front)->next = NULL;
		(q->front)->data = i;
		q->rear = q->front;
	}
	else {
		struct node *new_node = malloc(sizeof(struct node));
		if (new_node == NULL)
			terminate("Error in insert: queue is full.");
			
		(q->rear)->next = new_node;
		new_node->data = i;
		new_node->next = NULL;
		q->rear = new_node;
	}
	q->count++;
}

Item qremove(Queue q)
{
	struct node *old_front;
	Item value;
	
	if (is_empty(q))
		terminate("Error in remove: queue is empty.");
	
	q->count--;	
	
	old_front = q->front;
	value = old_front->data;
	q->front = old_front->next;
	free(old_front);
	// q->count--;                // After free(old_front), if there is no node, then making error. 
	return value;
}

Item first(Queue q)
{
	if (is_empty(q))
		terminate("Error in checking the first value: queue is empty.");
	
	return (q->front)->data;
}

Item last(Queue q)
{
	if (is_empty(q))
		terminate("Error in checking the last value: queue is empty.");
	
	return (q->rear)->data;
}

Item length(Queue q)
{
	return q->count;
}
