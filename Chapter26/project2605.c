// Write a program that prompts the user to enter two dates, then prints the difference between
// them, measured in days. Hint: Use the mktime and difftime functions. 

#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm t0, t1;
	time_t time0, time1;
	
	t0.tm_sec = t0.tm_min = t0.tm_hour = 0; // initialize unused members
	t0.tm_isdst = -1;
	
	t1.tm_sec = t1.tm_min = t1.tm_hour = 0; // initialize unused members
	t1.tm_isdst = -1;
	
	printf("Enter date (month/day/year): ");
	scanf(" %d/ %d/ %d", &t0.tm_mon, &t0.tm_mday, &t0.tm_year);
	t0.tm_mon--;
	t0.tm_year -= 1900;
	time0 = mktime(&t0);
	
	printf("Enter one more date (month/day/year): ");
	scanf(" %d/ %d/ %d", &t1.tm_mon, &t1.tm_mday, &t1.tm_year);
	t1.tm_mon--;
	t1.tm_year -= 1900;
	time1 = mktime(&t1);
	
	if (time0 <= time1)
		printf("\nThe difference of two dates is %ld days\n",
					 (long)difftime(time1, time0)/86400);
	else			 
		printf("\nThe difference of two dates is %ld days\n",
					 (long)difftime(time0, time1)/86400);
					 
	return 0;
}
