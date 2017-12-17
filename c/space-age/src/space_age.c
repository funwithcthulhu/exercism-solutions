#include "space_age.h"
#include <stdio.h>

#define EARTH 31557600

static const float period[8] = {
	EARTH * 1,
	EARTH * 0.2408467,
	EARTH * 0.61519726,
	EARTH * 1.8808158,
	EARTH * 11.862615,
	EARTH * 29.447498,
	EARTH * 84.016846,
	EARTH * 164.79132,
};

float convert_planet_age(planet_t PLANET, long seconds)
{
	return seconds / period[PLANET];
}
