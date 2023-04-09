/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:20 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/09 21:02:09 by junyojeo         ###   ########.fr       */
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

void	free_all(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_join(philo[i].tid, NULL);
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_mutex_destroy(philo->info->fork);
	pthread_mutex_destroy(philo->info->end_flag_mutex);
	pthread_mutex_destroy(philo->info->print_mutex);
}

int	check_finish(t_info *info)
{
	pthread_mutex_lock(info->end_flag_mutex);
	if (info->end_flag == 1)
	{
		pthread_mutex_unlock(info->end_flag_mutex);
		return (0);
	}
	pthread_mutex_unlock(info->end_flag_mutex);
	return (1);
}

void	monitoring(t_info *info, t_philo *philo)
{
	int	i;
	int	now;

	while (1)
	{
		now = timer(philo, 0);
		i = -1;
		while (++i < info->number_of_philosophers)
		{
			if (info->time_to_die <= now - philo[i].eat_time)
			{
				pthread_mutex_lock(info->end_flag_mutex);
				pthread_mutex_lock(philo->info->print_mutex);
				info->end_flag = 1;
				printf("%d %d died\n", now, philo->num);
				pthread_mutex_unlock(philo->info->print_mutex);
				pthread_mutex_unlock(info->end_flag_mutex);
				return ;
			}
		}
		pthread_mutex_lock(philo->info->full_cnt_mutex);
		if (info->full_cnt == info->number_of_philosophers)
		{
			pthread_mutex_unlock(philo->info->full_cnt_mutex);
			pthread_mutex_lock(info->end_flag_mutex);
			info->end_flag = 1;
			pthread_mutex_unlock(info->end_flag_mutex);
			return ;
		}
		pthread_mutex_unlock(philo->info->full_cnt_mutex);
	}
}
