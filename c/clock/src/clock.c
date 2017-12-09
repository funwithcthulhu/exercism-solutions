#include "clock.h"

void clock(time_text_t time_text, int hour, int minute)
{
	char *text_hour = NULL;
	char *text_minute = NULL;
	int hours_in_mins;
	if (hour < 0) {
		hour = abs(hour);
		hour %= 24;
		hour = MAX_HOUR - hour;
	}
	if (minute < 0) {
		minute = abs(minute);
		hours_in_mins = hour * 60;
		hours_in_mins -= (minute % 1440);
		if (hours_in_mins < 0) {
			hour = MAX_MINUTES - abs(hours_in_mins);
			minute = hour % 60;
			hour = hour / 60;
		} else {
			minute = hours_in_mins % 60;
			hour = hours_in_mins / 60;
		}
	} else {
		hour += minute / 60;
		hour %= 24;
		minute %= 60;
	}

	asprintf(&text_hour, "%d", hour);
	asprintf(&text_minute, "%d", minute);
	pad(text_hour);
	pad(text_minute);
	strcat(time_text, text_hour);
	strcat(time_text, COLON);
	strcat(time_text, text_minute);
}

void clock_add(time_text_t time_text, int minute_offset)
{
	char *hour_text = calloc(2, sizeof(char));
	char *minute_text = calloc(2, sizeof(char));

	strncpy(hour_text, time_text, 2);
	strncpy(minute_text, time_text + 3, 2);

	int hour = atoi(hour_text);
	int minute = atoi(minute_text);

	memset(time_text, '\0', MAX_STR_LEN);
	clock(time_text, hour, minute + minute_offset);
}

void pad(char *text)
{
	if (strlen(text) < 2) {
		char temp = *text;
		text[0] = '0';
		text[1] = temp;
		text[2] = '\0';
	}
}
