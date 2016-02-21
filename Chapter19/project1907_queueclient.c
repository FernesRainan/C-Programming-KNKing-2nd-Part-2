// exercise 1903b linked list type queue test program

#include <stdio.h>
#include "queueADT.h"

int main (void)
{
	Queue q1;
	int i;
	
	q1 = create();
	
	insert(q1, 3);
	printf("Member's number of Queue is %d.\n", length(q1));
	insert(q1, 4);
	printf("Member's number of Queue is %d.\n", length(q1));
	insert(q1, 60);
	printf("the value of queue is %d\n", qremove(q1));
	printf("Member's number of Queue is %d.\n", length(q1));
	insert(q1, 80);
	printf("Member's number of Queue is %d.\n", length(q1));
	
	for(i = 0; i < 3; i++) {
		printf("the value of queue is %d\n", qremove(q1));
	}
	printf("Member's number of Queue is %d.\n", length(q1));
	
	insert(q1, 10);
	printf("the value of queue is %d\n", qremove(q1));
	
	for(i = 0; i < 100; i++) {
		insert(q1, i * 2);
	}
	printf("the value of queue is %d\n", qremove(q1));
	printf("Member's number of Queue is %d.\n", length(q1));
	
	printf("The first value is %d, The last value is %d\n", first(q1), last(q1));
	printf("Remove queue %d\n", qremove(q1));
	printf("Member's number of Queue is %d.\n", length(q1));
	printf("The first value is %d, The last value is %d\n", first(q1), last(q1));
	
	destroy(q1);
	
	return 0;
}
	

