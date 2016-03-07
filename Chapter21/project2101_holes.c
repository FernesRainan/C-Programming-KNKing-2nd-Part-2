// Write a program that declares the s structure (se Section 21.4) and prints the sizes and offsets
// of the a, b, and c members. (Use sizeof to fine sizes; use offsetof to find offsets.)
// Have the program print the size of the entire structure as well. From this information, 
// determine whether or not the structure has any holes. If it does, describe the location and
// size of each. 

#include <stdio.h>
#include <stddef.h>

struct s {
	char a;
	int b[2];
	float c;
};

int main(void)
{
	printf("a offset is %d, b offset is %d, c offset is %d\n",
		offsetof(struct s, a), offsetof(struct s, b), offsetof(struct s, c));
	
	printf("Sturcture S size of %d.\n", sizeof(struct s));
	
	return 0;
}

