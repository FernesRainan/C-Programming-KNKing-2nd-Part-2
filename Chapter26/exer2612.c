// Write a function that, when passed a year, returns a time_t value representing 12:00am.
// on the first day of that year. 

time_t first_day (int year)
{
	struct tm t;
	
	t.tm_year = year - 1900;
	t.tm_mday = 1;
	t.tm_mon = 0;                
	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = 0;
	
	return mktime(&t);
}

	
