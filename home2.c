#include "sys/time.h"

void _()
{
	t_infoval	*timeval;

	gettimeofday(timeval->tv_sec, timeval->tv_usec);
	while (1)
	{
		int i = 0;
		while (i < philo->number_of_philosophers)
		{
			fork_get(time, i);
			usleep(philo->time_to_eat);
			fork_put_down(time, i);
			usleep(philo->time_to_sleep);

		}
	}
}
