// Write an array based implementation of the queue module described in Exercise 1.
// Use three integers to keep track of the queue's status, with one integer storing the
// position of the first empty slot in the array (used when an item is inserted), the
// second storing the position of the next item to be removed, and the third storing the
// number of items in the queue. An insertion or removal that would cause either of the
// first two integers to be incremented past the end of the array should instead reset
// the variable to zero, thus causing it to "wrap around" to the beginning of the array.

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
	Item contents[QUEUE_SIZE];
	Item rear;                 // Item storing the position of the first empty slot         
	Item front;                // Item storing the position of the next item to be removed.
	int count;                 // Item storing the number of items in the queue.           
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
		terminate("Error in create: queue cound not be created.");
	q->rear = q->front = 0;
	q->count = 0;
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
	if(q->count == QUEUE_SIZE)
		terminate("Error in insert: queue is full.");
		
	if(q->rear == QUEUE_SIZE)
		q->rear -= QUEUE_SIZE;
		
	q->contents[q->rear++] = i ;
	
	q->count++;
}

Item qremove(Queue q)
{
	Item value;
	
	if (is_empty(q))
		terminate("Error in remove: queue is empty.");
		
	if(q->front == QUEUE_SIZE)
		q->front -= QUEUE_SIZE;
	
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
		return q->contents[QUEUE_SIZE - 1];
	else 
		return q->contents[--q->rear];
}

Item length(Queue q)
{
	return q->count;
}



