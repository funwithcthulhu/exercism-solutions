#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define RETURN_MSG "A:%i C:%i G:%i T:%i"
#define BUFFER 64


typedef char* string;
typedef const char* const_string;

string count(const_string dna_strand);
int validStrand(const_string dna_strand);
