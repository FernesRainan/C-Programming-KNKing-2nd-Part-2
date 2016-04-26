// Write a program that reads a date from the command line and displays it in the following
// form:
// September 13, 2010
// Allow the user to enter the date as either 9-13-2010 or 9/13/2010; you may assume that
// there are no spaces in the date. Print an error message if the date doesn't have one of the
// specified forms. Hint: Use sscanf to extract the month, day, and year from the command-line
// argument.

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "%s 9-13-2010 || 9/13/2010\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int mm, dd, yyyy;
	char *months[13] = {"INVALID", 
		                  "January", "February", "March",
		                  "April", "May", "June",
		                  "July", "August", "September",
		                  "Octobre", "November", "December"};
  
  for (int i = 1; i < argc; i++) {
  	sscanf(argv[i], "%2d%*[-/]%2d%*[-/]%4d", &mm, &dd, &yyyy);
  	if (mm < 1 || mm > 12) {
  		fprintf(stderr, "Invalid month: %d\n", mm);
  		continue;
  	}
  	printf("%s %d, %d\n", months[mm], dd, yyyy);
  }
  
  return 0;
}


		
