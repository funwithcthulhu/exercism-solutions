#include "rna_transcription.h"

char* to_rna(const char *dna)
{
	char *rna = malloc(sizeof(dna));
	const char *bp;
	char ch;
	int counter = 0;
	bp = dna;
	while ((ch = *bp++) != '\0')
	{
		if (dna[counter] == 'G')
			rna[counter] = 'C';
		else if (dna[counter] == 'C')
			rna[counter] = 'G';
		else if (dna[counter] == 'A')
			rna[counter] = 'U';
		else if (dna[counter] == 'T')
			rna[counter] = 'A';
		else
		{
			free(rna);
			return NULL;
		}	
		counter++;
	}
	rna[counter + 1] = '\0';
	return rna;
}
