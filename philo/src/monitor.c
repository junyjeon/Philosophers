/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:58:22 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/10 03:27:02 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static int	check_full(t_info *info)
{
	pthread_mutex_lock(info->full_cnt_mutex);
	if (info->full_cnt == info->number_of_philosophers)
	{
		pthread_mutex_unlock(info->full_cnt_mutex);
		pthread_mutex_lock(info->end_flag_mutex);
		info->end_flag = 1;
		pthread_mutex_unlock(info->end_flag_mutex);
		return (0);
	}
	pthread_mutex_unlock(info->full_cnt_mutex);
	return (1);
}

static int	check_died(t_info *info, t_philo *philo)
{
	int	i;
	int	now;

	now = timer(philo, 0);
	i = -1;
	while (++i < info->number_of_philosophers)
	{
		pthread_mutex_lock(info->full_cnt_mutex);
		if (info->time_to_die <= now - philo[i].eat_time)
		{
			pthread_mutex_unlock(info->full_cnt_mutex);
			pthread_mutex_lock(info->end_flag_mutex);
			info->end_flag = 1;
			pthread_mutex_unlock(info->end_flag_mutex);
			pthread_mutex_lock(info->print_mutex);
			printf("%d %d died\n", now, philo[i].num);
			pthread_mutex_unlock(info->print_mutex);
			return (0);
		}
		pthread_mutex_unlock(info->full_cnt_mutex);
	}
	return (1);
}

void	monitoring(t_info *info, t_philo *philo)
{
	while (1)
	{
		if (!check_died(info, philo))
			break ;
		if (!check_full(info))
			break ;
	}
}
