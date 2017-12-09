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
	int days_months_prior = 0;
	int int_day_of_week;
	int teenths[7];
	char *temp = calloc(10, sizeof(char));

	for (int j = 0; j < 7; j++)
	{
		memset(temp, '\0', 10);
		temp = strdup(DAYS_OF_WEEK[j]);
		if (strcmp(temp, day) == 0)
		{
			int_day_of_week = j;
			printf("day of week: %i\n", int_day_of_week);
			break;
			
		}
		
	}
	
	// get total days of all months prior to target month
	for (int i = 1; i < month; i++)
	{
		days_months_prior += DAYS_OF_MONTH[i];
	}

	// get first xxxxxx of month
	int first_of_month = (jan_first + days_months_prior) % 7;
	int first_x_day = 1;
	int times = 0;
	for (int d = first_of_month; d < first_of_month + 7; d++)
	{
		if (int_day_of_week == (d % 7))
		{
			times += 1;
			
			break;
		}
			
		first_x_day++;
	}

	if (strcmp(monthday, "first") == 0)
		return first_x_day;

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
			printf("teenths: %i\n", teenths[o]);
			if (teenths[o] == int_day_of_week)
			{
				return o + 13;
			}

		}
	}

	int day_number = -1;
	return day_number;
}

int is_leap_year(unsigned short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int january_first(int year)
{
	int y = year % 100 - 1;
	int c = year / 100;
	int var = (y / 4);
	if (y == -1)
		var = -1;
	return mod((29 + y + var + (c/4) - (2 * c)), 7);
}

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
