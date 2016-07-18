// Write programs that display the current date and time in each of the following formats. Use
// strftime to do all or most of the formatting. 

// (b) Sun, 3 Jun 07  17:48

#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t current = time(NULL);
	char date_time[22];
	
	strftime(date_time, sizeof(date_time), "%a, %d %b %y  %H:%M", localtime(&current));
	
	puts(date_time);
	
	return 0;
}
