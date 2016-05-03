// Write a program that reads a series of phone numbers from a file and displays them in a 
// standard format. Each line of the file will contain a single phone number, but the numbers
// may be in a variety of formats. You may assume that each line contains 10 digits, possibly
// mixed with other characters (which should be ignored). For example, suppose that the file 
// contains the following lines:
//    404.817.6900
//    (215) 686-1776
//    312-746-6000
//    877 275 5273
//    6173434200
// The output of the program should have the following appearance:
//   (404) 817-6900
//   (215) 686-1776
//   (312) 746-6000
//   (877) 275-5273
//   (617) 343-4200
// Have the program obtain the file name from the command line. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_LEN 30

void make_number(char *word);
	
int main (int argc, char *argv[])
{
	FILE *in_fp, *out_fp;
	char phone[NUMBER_LEN + 1];
	char outstr[NUMBER_LEN + 5];
	
	if (argc != 3) {
		fprintf(stderr, "usage: phone_format infile outfile\n");
		exit(EXIT_FAILURE);
	}
	
	if ((in_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
		
	if ((out_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while (fgets(phone, sizeof(phone), in_fp) != NULL) {
		make_number(phone);
		sprintf(outstr, "(%c%c%c) %c%c%c-%c%c%c%c\n", phone[0], phone[1], phone[2],
		                                            phone[3], phone[4], phone[5],
		                                            phone[6], phone[7], phone[8], phone[9]);
		fputs(outstr, out_fp);
	}
	
	fclose(in_fp);
	fclose(out_fp);
	
	return 0;
}

void make_number(char *word)
{
  int i, j = 0;
   
  for (i = 0; word[i] != '\n'; i++) {
    if (isdigit (word[i]))
    	word[j++] = word[i];
  }
  word[j] = '\0';
  
  return;
}
