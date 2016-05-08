// Using isalpha and isalnum, write a function that checks whether a string has the 
// syntax of a C identifier (it consists of letters, digits, and underscores, with a letter or
// underscore at the beginning.)

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 31

char keyword[][10]={"auto","break","case","char","const","continue",
										"default","printf", "double","else","enum","extern",
										"float","for","goto","if","int","do",
										"long","register","return","short","signed","sizeof",
										"static","struct","switch","typedef","union","unsigned",
										"void","volatile","while"};

int main(void)
{
	char str[SIZE + 1];
	int len, i, flag = false;
	
	printf("Enter The C Identifier :> ");
	gets(str);

	for( i = 0 ; i <= 32 ; i++ ) { 
		if(strcmp(str, keyword[i])==0) 
			{ 
				printf(" Given string is invalid Identifier\n");
				exit(EXIT_FAILURE);
			}
	} 

	if( str[0]=='_' || isalpha(str[0]) ) { 
		flag = true;
		
		len = strlen(str); 
		
		for(i = 1 ; i < len ; i++ ) {
			if( str[i]=='_' || isalnum(str[i]) )
				continue;
			else {
				flag= false;
				break;
			}
		}
	} 

	if( flag == true )
		printf("Given string is a valid C Identifier\n");
	else 
		printf("Given string is invalid C Identifier\n");
	return 0;
}
