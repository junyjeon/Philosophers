/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:20 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/09 22:09:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	timer(t_philo *philo, int flag)
{
	struct timeval	mytime;
	long long		now;

	if (gettimeofday(&mytime, NULL) == -1)
		return (ft_perror("Error: tv or tz cannot access."));
	now = mytime.tv_sec * 1000;
	now += mytime.tv_usec / 1000;
	if (flag)
		return (now);
	return (now - philo->info->start_time);
}

int	ft_usleep(t_philo *philo, int now, int time)
{
	int	target;

	target = now + time;
	while (now < target)
	{
		if (philo->info->time_to_die <= now - philo->eat_time)
		{
			pthread_mutex_unlock(&philo->info->fork[philo->num - 1]);
			pthread_mutex_unlock(&philo->info->fork[(philo->num) % \
			philo->info->number_of_philosophers]);
			return (0);
		}
		usleep(1000);
		now = timer(philo, 0);
	}
	return (1);
}

int	print_mutex(char *str, int now, t_philo *philo)
{
	if (!check_finish(philo->info))
		return (0);
	pthread_mutex_lock(philo->info->print_mutex);
	printf("%d %d %s", now, philo->num, str);
	pthread_mutex_unlock(philo->info->print_mutex);
	if (!check_finish(philo->info))
		return (0);
	return (1);
}
