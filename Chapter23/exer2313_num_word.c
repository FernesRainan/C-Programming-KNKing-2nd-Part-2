// Use strtok to write the following function:
// int count_words(char *sentence);
// count_words returns the number of words in the string sentence, where a "word" is
// any sequence of non_white_space characters. count_words is allowed to modify the
// string.

#include <stdio.h>
#include <string.h>

int count_words(char *sentence)
{
	char *word;
	char token[] = " ,.!:;\t";
	int count = 0;
	
	while ((word = strtok(sentence, token)) != NULL) {
		count++;
		sentence = NULL;
	}
	
	return count;
	
}

int main(void)
{
	char s[] = "This is the example. How many words.";
	
	printf("The number of words is %d\n", count_words(s));
	
	return 0;
}
