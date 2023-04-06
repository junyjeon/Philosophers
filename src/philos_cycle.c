/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/06 18:06:41 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	eating(t_philo *philo)
{
	long long timer;

	timer = get_time(philo);
	pthread_mutex_lock(philo->lfork);
	printf("%lld %d has taken a left fork\n", timer - philo->info->start_time, philo->num);
	
	timer = get_time(philo);
	pthread_mutex_lock(philo->rfork);
	printf("%lld %d has taken a right fork\n", timer - philo->info->start_time, philo->num);
	
	timer = get_time(philo);
	philo->eat_time = timer;
	philo->cnt_eat++;
	
	printf("%lld %d is eating\n", timer - philo->info->start_time, philo->num);
	if (!ft_usleep(philo, timer, philo->info->time_to_eat))
		return (0);
	
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (1);
}

static void	philos_cycle(t_philo *philo)
{
	int			i;

	philo->info->start_time = get_time(philo);
	philo->eat_time = philo->info->start_time;
	if (philo->num % 2 == 1)
		ft_usleep(philo, get_time(philo), 1);
	i = -1;
	while (1)
	{
		if (philo->info->must_eat == 0)
			return ;
		if (philo->info->end_flag == 1)
			return ;
		if (!eating(philo))
			return ;
		if (philo->cnt_eat == philo->info->must_eat)
			return ;
		printf("%lld %d is sleeping\n", get_time(philo) - philo->info->start_time, philo->num);
		ft_usleep(philo, get_time(philo), philo->info->time_to_sleep);
		printf("%lld %d is thinking\n", get_time(philo) - philo->info->start_time, philo->num);
	}
}

int	philos_born(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->number_of_philosophers)
	{
		if (pthread_create(&philo[i].tid, 0, (void *)philos_cycle, (t_philo *)&philo[i]) != 0)
		{
			ft_perror("Error: Thread creation failed.");
			all_free(philo);
			return (0);
		}
	}
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_join(philo[i].tid, 0);
	return (1);
}
