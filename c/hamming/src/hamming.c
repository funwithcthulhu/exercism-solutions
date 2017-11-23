#include "hamming.h"

int compute(char *strandA, char *strandB)
{
	int distance = 0;

	if (!strandA || !strandB)
		return -1;

	if (strlen(strandA) != strlen(strandB))
		return -1;

	for (unsigned long i = 0; i < strlen(strandA); i++)
	{
		if (strandA[i] != strandB[i])
			distance++;
	}
	return distance;
}
