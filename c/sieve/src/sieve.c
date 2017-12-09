#include "sieve.h"

unsigned int sieve(const unsigned int limit, primes_array_t primes)
{
	if (limit < 2)
		return 0;

	unsigned char *primes_array = calloc(limit + 1, sizeof(char));
	memset(primes_array, 1, limit + 1);
	memset(primes, 0, sizeof(*primes));
	unsigned int number_of_primes = 0;
	for (unsigned int i = 0; i < 2; i++) {
		primes_array[i] = 0;
	}

	for (unsigned int index = 2; index < (sqrt(limit) + 1);) {
		for (unsigned int non_prime_index = (index * 2);
			non_prime_index < (limit + 1);
			non_prime_index += index) {
				primes_array[non_prime_index] = 0;
			}
		do {
			index++;
			if (primes_array[index]) break;
		} while (index <= (sqrt(limit) + 1));
	}
	for (unsigned int j = 1; j < (limit + 1); j++) {
		if (primes_array[j])
			primes[number_of_primes++] = j;
	}
	free(primes_array);
	return number_of_primes;

}
