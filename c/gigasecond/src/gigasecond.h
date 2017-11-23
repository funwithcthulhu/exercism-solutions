#include <time.h>
#define GIGASECOND 1000000000

time_t gigasecond_after(time_t beginning_date)
{
	return beginning_date + GIGASECOND;
}
