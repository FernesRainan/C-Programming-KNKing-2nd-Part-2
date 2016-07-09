// Section 26.3 described some of the ISO 8601 date and time formats. Here are a few more:
// Give strftime strings that correspond to each of theses formats. 

#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t current = time(NULL);
	struct tm *ptr;
	char date_time[50];
			
// (a) Year followed by day of year: YYYY-DDD, where DDD is a number between 001 and 366
	strftime(date_time, sizeof(date_time),
	         "%Y-%j\n", localtime(&current));
	puts(date_time);
		
// (b) Year, week, and day of week: YYYY-Www-D, where ww is a number between 01 and 53,
// and D is a digit between 1 through 7, beginning with Monday and ending with Sunday	
	strftime(date_time, sizeof(date_time),
	         "%Y-W%V-%u\n", localtime(&current));
	puts(date_time);	
		
// (c) Combined date and time: YYYY-MM-DDThh:mm:ss
	strftime(date_time, sizeof(date_time),
	         "%Y-%m-%dT%T\n", localtime(&current));
	puts(date_time);	
		
	return 0;
}
