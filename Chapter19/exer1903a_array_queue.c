// Write an array based implementation of the queue module described in Exercise 1.
// Use three integers to keep track of the queue's status, with one integer storing the
// position of the first empty slot in the array (used when an item is inserted), the
// second storing the position of the next item to be removed, and the third storing the
// number of items in the queue. An insertion or removal that would cause either of the
// first two integers to be incremented past the end of the array should instead reset
// the variable to zero, thus causing it to "wrap around" to the beginning of the array.

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 100

static int contents[QUEUE_SIZE];
static int rear = 0;     // integer storing the position of the first empty slot
static int front = 0;    // interger storing the position of the next item to be removed. 
static int count = 0;    // interger storing the number of items in the queue.

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

bool is_empty(void)
{
	return count == 0;
}

void insert(int i)
{
	if(count == QUEUE_SIZE)
		terminate("Error in insert: queue is full.");
		
	if(rear == QUEUE_SIZE)
		rear -= QUEUE_SIZE;
		
	contents[rear++] = i ;
	
	count++;
}

int qremove(void)
{
	int value;
	
	if (is_empty())
		terminate("Error in remove: queue is empty.");
		
	if(front == QUEUE_SIZE)
		front -= QUEUE_SIZE;
	
	count--;
	
	value = contents[front];
	contents[front++] = 0;
		
	return value;
}

int first(void)
{
	if (is_empty())
		terminate("Error in checking the first value: queue is empty.");
	
	return contents[front];
}

int last(void)
{
	if (is_empty())
		terminate("Error in checking the last value: queue is empty.");
	
	if (rear == 0) 
		return contents[QUEUE_SIZE - 1];
	else 
		return contents[--rear];
}


