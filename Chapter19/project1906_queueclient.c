// Write an array based implementation of the queue module described in Exercise 1.
// Use three integers to keep track of the queue's status, with one integer storing the
// position of the first empty slot in the array (used when an item is inserted), the
// second storing the position of the next item to be removed, and the third storing the
// number of items in the queue. An insertion or removal that would cause either of the
// first two integers to be incremented past the end of the array should instead reset
// the variable to zero, thus causing it to "wrap around" to the beginning of the array.

// Modify Programming Project 5 so that the items in a queue are stored in a dynamically 
// allocated array whose length is passed to the create function. 

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
	Item *contents;
	Item rear;                 // Item storing the position of the first empty slot         
	Item front;                // Item storing the position of the next item to be removed.
	int count;                 // Item storing the number of items in the queue.           
	int size;                  // queue size indicator. 
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(int size)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created.");
	q->contents = malloc(size * sizeof(Item));
	if (q->contents == NULL){
		free(q);
		terminate("Error in create: queue could not be created.");
	}
	
	q->rear = q->front = 0;
	q->count = 0;
	q->size = size;
	return q;
}

void destroy(Queue q)
{
	free(q);
}


bool is_empty(Queue q)
{
	return q->count == 0;
}

void insert(Queue q, Item i)
{
	if(q->count == q->size)
		terminate("Error in insert: queue is full.");
		
	if(q->rear == q->size)
		q->rear -= q->size;
		
	q->contents[q->rear++] = i ;
	
	q->count++;
}

Item qremove(Queue q)
{
	Item value;
	
	if (is_empty(q))
		terminate("Error in remove: queue is empty.");
		
	if(q->front == q->size)
		q->front -= q->size;
	
	q->count--;
	
	value = q->contents[q->front];
	q->contents[q->front++] = 0;
		
	return value;
}

Item first(Queue q)
{
	if (is_empty(q))
		terminate("Error in checking the first value: queue is empty.");
	
	return q->contents[q->front];
}

Item last(Queue q)
{
	if (is_empty(q))
		terminate("Error in checking the last value: queue is empty.");
	
	if (q->rear == 0) 
		return q->contents[(q->size) - 1];
	else 
		return q->contents[--q->rear];
}

Item length(Queue q)
{
	return q->count;
}
