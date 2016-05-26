// Write a program that prompts the user to enter a series of words separated by single spaces,
// then prints the words in reverse order. Read the input as a string, and then use strtok to 
// break it into words.

#include <stdio.h>
#include <string.h>

#define MAX 10

void reverse_words(char *sentence)
{
	char *word;
	char token[] = " ";
	int i, count = 0;
	char *position[MAX];
	
	while ((word = strtok(sentence, token)) != NULL) {
		position[count++] = word;
		sentence = NULL;
	}
	
	for (i = count - 1; i >= 0; i--) 
		printf("%s ", position[i]);
	
	putchar('\n');
	
	return;
	
}

int main(void)
{
	char s[] = "cat dog bird cow pig goat";
	
	printf("The original is \n%s\n\n", s);
	 
	printf("The result is \n");
	reverse_words(s);
	putchar('\n');
	
	return 0;
}
