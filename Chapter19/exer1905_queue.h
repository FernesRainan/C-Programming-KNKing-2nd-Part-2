// Modify the queue.h header of Exercise 1 so that it defines a Queue type, where Queue
// is a structure containing a fixed-length array (see Exercise 3(a). Modify the functions in
// queue.h to take a Queue * parameter. 

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define QUEUE_SIZE 100

typedef struct {
	int contents[QUEUE_SIZE];
	int rear;
	int front;
} Queue;

void insert(Queue *q, int i);
int remove(Queue *q);
int first(const Queue *q);
int last(const Queue *q);
bool is_empty(const Queue *q);

#endif
