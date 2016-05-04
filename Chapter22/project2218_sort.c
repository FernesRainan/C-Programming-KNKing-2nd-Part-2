// Write a program that reads integers from a text file whose name is given as a command-line
// argument. Each line of the file may contain any number of integers (including none) 
// separated by one or more spaces. Have the program display the largest number in the file, the
// smallest number, and the median (the number closest to the middle if the integers where
// sorted). If the file contains an even number of integers, there will be two numbers in the
// middle; the program should display their average (rounded down). You may assume that the
// file contains no more than 10,000 integers. Hint: Store the integers in an array and then sort
// the array. 

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10000

int compare (const void *a, const void *b)
{
	return ( *(int *)a - *(int *)b );
}

int main (int argc, char *argv[])
{
	FILE *in_fp;
	int i, j, buffer[ARRAY_MAX];
	long sum = 0;
	int str;
		
	if((in_fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open the file.\n");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < ARRAY_MAX ; i++) {
		if ((fscanf(in_fp, " %d", &str)) == EOF)
			break;
		buffer[i] = str;
		sum += buffer[i];
	}
	
	qsort(buffer, i, sizeof(int), compare);
		
	printf("The smallest is %d\n", buffer[0]);
	printf("The largest is %d\n", buffer[i - 1]);
	if (i % 2)
		printf("The median is %d\n", buffer[i / 2]);	
	else
		printf("The medians are %d and %d\n", buffer[(i/2) - 1], buffer[i/2]);
	printf("The average of %d integers is %d.\n", i, (sum / i));
	
	for (j = 0; j < i; j++)
		printf("%d: %d\n", j, buffer[j]);
		
	fclose(in_fp);
	
	return 0;		
	
}
