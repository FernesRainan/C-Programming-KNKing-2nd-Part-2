// Write programs that display the current date and time in each of the following formats. Use
// strftime to do all or most of the formatting. 

// (c) 06/03/07  5:48:34 PM

#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t current = time(NULL);
	struct tm *ptr;
	char date[9], time[12];
	
	ptr = localtime(&current);
	strftime(date, sizeof(date), "%m/%d/%y", ptr);
	strftime(time, sizeof(time), "%I:%M:%S %p", ptr);
	
	printf("%s  %s\n", date, time[0] == '0' ? &time[1] : time);
		
	return 0;
}
