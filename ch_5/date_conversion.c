#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	
	if (day > *(*(daytab+leap)+month)) {
		printf("ERROR: INCORRECT ENTRY\n");
		return 0;
	}
	for (i = 1; i < month; i++)
		day += *(*(daytab+leap)+i);
	return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if (year < 0) {
		printf("ERROR: INCORRECT ENTRY\n");
		return 0;
	}
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > *(*(daytab+leap)+i); i++)
		yearday -= *(*(daytab+leap)+i);
	*pmonth = i;
	*pday = yearday;

	return 1;
}

/* driver for month_day and day_of_year */
int main()
{
	int year = 1992;
	int month = 8;
	int day = 17;
	int pmonth;
	int pday;

	printf("%d\n", day_of_year(year, month, day));
	
	month_day(year, 321, &pmonth, &pday);
	
	printf("%d %d\n", pmonth, pday);

	return 0;
}




