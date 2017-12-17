#include "nucleotide_count.h"

//	snprintf(header, 128, HTTP_GET_MSG, loc, host);

string count(const_string dna_strand)
{
	int A = 0;
	int C = 0;
	int G = 0;
	int T = 0;
	string count = calloc(BUFFER, sizeof(char));

	for (size_t i = 0; i < strlen(dna_strand); i++) {
		if (dna_strand[i] == 'A') A++;
		if (dna_strand[i] == 'C') C++;
		if (dna_strand[i] == 'G') G++;
		if (dna_strand[i] == 'T') T++;
	}
	snprintf(count, BUFFER, RETURN_MSG, A, C, G, T);

	if (!validStrand(dna_strand))
		memset(count, '\0', BUFFER);

	return count;
}

int validStrand(const_string dna_strand)
{
	for (size_t i = 0; i < strlen(dna_strand); i++) {
		if (dna_strand[i] != 'A' && 
			dna_strand[i] != 'C' &&
			dna_strand[i] != 'G' &&
			dna_strand[i] != 'T')
			return 0;
	}
	return 1;
}
