#include "beer_song.h"

void verse(char *response, int verse)
{
	switch (verse)
	{
		case 0:
			strcpy(response, NO_BEERS);
			break;
		case 1:
			strcpy(response, ONE_BEER);
			break;
		case 2:
			strcpy(response, TWO_BEERS);
			break;
		default:
			snprintf(response, BUFFER_SIZE, "%d bottles of beer on the wall, %d bottles of "
                               				"beer.\nTake one down and pass it around, %d "
                               				"bottles of beer on the wall.\n",
											verse, verse, verse - 1);
	}
}

void sing(char *response, int start, int finish)
{
	char buffer[BUFFER_SIZE];
	char *target = response;
	char *bp;
	char ch;

	for (int i = start; i >= finish; i--)
	{
		if (i != start)
			*target++ = '\n';
		
		verse(buffer, i);
		bp = buffer;
		while ((ch = *bp++) != '\0')
			*target++ = ch;
	}
	*target = '\0';
}
