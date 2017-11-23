#include <string.h>
#include <ctype.h>

#define RESPONSE1 "Sure."
#define RESPONSE2 "Whoa, chill out!"
#define RESPONSE3 "Fine. Be that way!"
#define RESPONSE4 "Whatever."

const char* hey_bob(char *phrase);
int isAllCaps(char *phrase);
int noAlphas(char *phrase);
char getLastChar(char *phrase);
