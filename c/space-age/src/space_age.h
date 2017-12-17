typedef enum planets {
	EARTH,
	MERCURY,
	VENUS,
	MARS,
	JUPITER,
	SATURN,
	URANUS,
	NEPTUNE
} planet_t;

float convert_planet_age(planet_t PLANET, long seconds);
