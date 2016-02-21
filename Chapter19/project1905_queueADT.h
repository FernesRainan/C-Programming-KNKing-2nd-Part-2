// A queue is similar to a stack, except that items are added at one end but removed from
// the other in a FIFO fashion. Operations on a queue might include:

// Inserting an item at the end of the queue
// Removing an item from the beginning of the queue
// Returning the first item in the queue (without changing the queue)
// Returning the last item in the queue (without changing the queue)
// Testing whether the queue is empty

// Write an interface for a queue module in the form of a header file named queue.h

#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue create(void);
void destroy(Queue q);
void insert(Queue q, Item i);
Item qremove(Queue q);
Item first(Queue q);
Item last(Queue q);
bool is_empty(Queue q);
Item length(Queue q);

#endif

