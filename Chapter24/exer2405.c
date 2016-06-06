// In the inventory.c program (see Section 16.3), the main function has a for loop that
// prompts the user to enter an operation code, reads the code, and then calls either insert, 
// search, update, or print. Add a call of setjmp to main in such a way that a 
// subsequent call of longjmp will return to the for loop. (After the longjmp, the user will 
// be prompted for an operation code, and the program will continue normally) setjmp will
// need a jmp_buf variable, where should it be declared?
#include <stdio.h>

int main (void)
{
	char code;
	
	for (;;) {
		setjmp(env);
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n')
		;
		switch (code) {
			case 'i' : insert();
				         break;
			case 's' : search();
				         break;
		  case 'u' : update();
		  	         break;
		  case 'p' : print();
		  	         break;
		  case 'q' : return 0;
		  default:   printf("Illegal code\n");
		}
		printf("\n");
	}
}
// jmp_buf variable env will need to be global. 
