/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:00 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/07 13:13:52 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_perror(char *str)
{
	printf("%s\n", str);
	return (0);
}

long long	timer(t_philo *philo, int flag)
{
	struct timeval	mytime;
	long long		now;

	if (gettimeofday(&mytime, NULL) == -1)
		return (ft_perror("Error: It points to areas where tv or tz cannot access."));
	now = mytime.tv_sec * 1000;
	now += mytime.tv_usec / 1000;
	if (flag)
		return (now);
	return (now - philo->info->start_time);
}

int	ft_usleep(t_philo *philo, long long now, int time_to_spend)
{
	long long	target;

	target = now + time_to_spend;
	while (now < target)
	{
		// 죽는시간 <= 현재시간 - 마지막으로 먹은시간
		if (philo->info->time_to_die <= now + philo->eat_time)
		{
			printf("%lld %d is died\n", now, philo->num);
			pthread_mutex_lock(philo->info->end_flag_mutex);
			philo->info->end_flag = 1;
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			return (0);
		}
		usleep(100);
		now = timer(philo, 0);
	}
	return (1);
}

int	all_free(t_philo *philo)//join status != 0
{
	int	i;
	int	status;

	i = -1;
	while (++i < philo->info->number_of_philosophers)
	{
		pthread_join(philo->tid, (void **)&status);
		if (status != 0)
			return (ft_perror("Error: Failed to release thread resources."));
		if (pthread_mutex_destroy(philo[i].lfork) != 0)
			return (ft_perror("Error: mutex destroy fail"));
		if (pthread_mutex_destroy(philo[i].rfork) != 0)
			return (ft_perror("Error: mutex destroy fail"));
	}
	return (1);	
}
