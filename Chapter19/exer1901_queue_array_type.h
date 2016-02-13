// A queue is similar to a stack, except that items are added at one end but removed from
// the other in a FIFO fashion. Operations on a queue might include:

// Inserting an item at the end of the queue
// Removing an item from the beginning of the queue
// Returning the first item in the queue (without changing the queue)
// Returning the last item in the queue (without changing the queue)
// Testing whether the queue is empty

// Write an interface for a queue module in the form of a header file named queue.h

// Array based implementation of the queue module

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 100
#define int qItem

typedef struct {
	int contents[QUEUE_SIZE];
	int order;
} Queue;

void q_insert(Queue *q, qItem i);
qItem q_remove(Queue *q);
qItem q_first(const Queue *q);
qItem q_last(const Queue *q);
bool q_is_empty(const Queue *q);

#endif

