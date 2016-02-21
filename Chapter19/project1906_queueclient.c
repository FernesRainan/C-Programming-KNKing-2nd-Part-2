// exercise 1903a array type queue test program

// Modify Programming Project 5 so that the items in a queue are stored in a dynamically 
// allocated array whose length is passed to the create function. 

#include <stdio.h>
#include "queueADT.h"

int main (void)
{
	Queue q1;
	int i;
	
	q1 = create(100);
	
	insert(q1, 3);
	insert(q1, 4);
	insert(q1, 60);
	insert(q1, 80);
	
	for(i = 0; i < 4; i++) {
		printf("the value of queue is %d\n", qremove(q1));
	}
	
	for(i = 0; i < 100; i++) {
		insert(q1, i * 2);
	}
	
	printf("The first value is %d, The last value is %d\n", first(q1), last(q1));
	printf("Remove queue %d\n", qremove(q1));
	printf("Member's number of Queue is %d.\n", length(q1));
	
	destroy(q1);
	
	return 0;
}
	

