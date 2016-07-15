// Write a program that prompts the user for a date (month, day, and year) and an integer n,
// then prints the date that's n days later.

#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm t;
	int n;
	
	t.tm_sec = t.tm_min = t.tm_hour = 0; // initialize unused members
	t.tm_isdst = -1;
	
	printf("Enter month (1-12): ");
	scanf("%d", &t.tm_mon);
	t.tm_mon--;
	
	printf("Enter day(1-31): ");
	scanf("%d", &t.tm_mday);
	
	printf("Enter year: ");
	scanf("%d", &t.tm_year);
	t.tm_year -= 1900;
	
	printf("Enter number of days in future: ");
	scanf("%d", &n);
	
	t.tm_mday += n;
	mktime(&t);            // adjust date
	printf("\nFuture date: %d/%d/%d\n",
				 t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);
	
	return 0;
}
