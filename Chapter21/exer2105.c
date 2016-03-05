#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;
	
	printf("Enter a character: ");
	scanf("%c", &c);
	
	if (islower(c))
		printf("It is lower character\n");
	else 
		printf("It is not lower character\n");
		
	return 0;
}
