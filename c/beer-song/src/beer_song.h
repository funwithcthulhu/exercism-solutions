#include <stdio.h>
#include <string.h>

#ifndef _BEER_SONG_H
#define _BEER_SONG_H

#define BUFFER_SIZE   (1024)
#define TWO_BEERS "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n"

#define ONE_BEER "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n"

#define NO_BEERS "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n"

#endif

void verse(char *response, int verse);
void sing(char *response, int start, int finish);
