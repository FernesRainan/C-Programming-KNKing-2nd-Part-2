// exercise 1903b linked list type queue test program

#include <stdio.h>
#include "queue.h"
#include "queue2.c"

int main (void)
{
	int i;
	
	insert(3);
	insert(4);
	insert(60);
	insert(80);
	
	for(i = 0; i < 4; i++) {
		printf("the value of queue is %d\n", qremove());
	}
	
	for(i = 0; i < 100; i++) {
		insert(i * 2);
	}
	
	printf("The first value is %d, The last value is %d\n", first(), last());
	
	printf("Remove queue %d\n", qremove());
	
	insert(2);
	insert(4);     //checking error status ==> meaningless
	
	return 0;
}
	

