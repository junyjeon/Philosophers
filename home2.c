#include "sys/time.h"

typedef struct s_timeval
{
    time_t        tv_sec;     // seconds
    suseconds_t   tv_usec;    // microseconds
} t_timeval;

void _()
{
	t_timeval	*timeval;

	gettimeofday(timeval->tv_sec, timeval->tv_usec);
	while (1)
	{
		int i = 0;
		while (i < time->number_of_philosophers)
		{
			fork_get(time, i);
			usleep(time->time_to_eat);
			fork_put_down(time, i);
			usleep(time->time_to_sleep);

		}
	}
}