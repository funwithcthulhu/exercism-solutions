#include "meetup.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

const int DAYS_OF_MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *DAYS_OF_WEEK[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int meetup_day_of_month(int year, int month, char *monthday, char *day)
{

	int jan_first = january_first(year);
	int int_day_of_week = dayOfWeek(day);
	int days_months_prior = 0;
	int teenths[7];

	if (is_leap_year(year) && month > 2)
		days_months_prior += 1;
	
	// get total days of all months prior to target month
	for (int i = 1; i < month; i++)
		days_months_prior += DAYS_OF_MONTH[i];

	// get x of month
	int first_of_month = (jan_first + days_months_prior) % 7;
	int x_day = 1;
	int times = 0;
	int max_days = DAYS_OF_MONTH[month] + first_of_month;

	// add 1 for 29 days in feb of a leap year
	if (is_leap_year(year) && month == 2)
		max_days += 1;

	for (int d = first_of_month; d < max_days; d++)
	{
		if (int_day_of_week == (d % 7))
			times += 1;
		
		if (strcmp(monthday, "first") == 0 && times == 1)
			return x_day;

		if (strcmp(monthday, "second") == 0 && times == 2)
			return x_day;

		if (strcmp(monthday, "third") == 0 && times == 3)
			return x_day;

		if (strcmp(monthday, "fourth") == 0 && times == 4)
			return x_day;

		if (strcmp(monthday, "fifth") == 0 && times == 5)
			return x_day;

		if (strcmp(monthday, "last") == 0 && (max_days - d <= 7) && int_day_of_week == (d % 7))
			return x_day;

		x_day++;
	}	

	// generate teenths
	int m = 12;
	for (int t = 0; t < 7; t++)
	{
		teenths[t] = (m + first_of_month) % 7;
		m++;
	}

	// return a teenth answer
	if (strcmp(monthday, "teenth") == 0)
	{
		for (int o = 0; o < 7; o++)
		{
			if (teenths[o] == int_day_of_week)
				return o + 13;
		}
	}

	return 0;
}

// convert day to day of week == 0-6 (Sunday == 0)
int dayOfWeek(char *day)
{
	char *temp = calloc(10, sizeof(char));
	for (int j = 0; j < 7; j++)
	{
		memset(temp, '\0', 10);
		temp = strdup(DAYS_OF_WEEK[j]);
		if (strcmp(temp, day) == 0)
			return j;
	}
	free(temp);

	return -1; // only reaches here returns if there is something wrong
}

int is_leap_year(unsigned short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Disparate variation of Gauss's algorithm
int january_first(int year)
{
	int y = year % 100 - 1;
	int c = year / 100;
	int var = (y / 4);
	if (y == -1)
		var = -1;
	return mod((29 + y + var + (c/4) - (2 * c)), 7);
}

// implementation of modulo which works with negative numbers
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
