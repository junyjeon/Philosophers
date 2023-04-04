/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/04 20:26:21 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philo *philo)
{
	printf("%lld %d is sleeping", get_time(philo, -1), philo->num);
	ft_usleep(get_time(philo, -1), philo->info->time_to_sleep * 1000);
}

void	eating(t_philo *philo, long long start_time)
{
	pthread_mutex_lock(&philo->lfork);
	printf("%lld %d has taken a fork", get_time(philo, -1), philo->num);
	pthread_mutex_lock(&philo->rfork);
	printf("%lld %d has taken a fork", get_time(philo, -1), philo->num);
	printf("%lld %d is eating", get_time(philo, -1), philo->num);
	philo->count_eat++;
	philo->start_eat_time = start_time;
	ft_usleep(get_time(philo, -1), philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(&philo->rfork);
}

void	thinking(t_philo *philo)
{
	printf("%lld %d is thinking\n", get_time(philo, -1), philo->num);
}

void	philos_cycle(t_philo *philo)
{
	int	i;
	i = -1;
	while (1)
	{
		philo->info->start_time = get_time(philo, START_TIME);
		printf("current_time: %lld\n", get_time(philo, 1));
		return ;
		if (philo->count_eat == philo->info->number_of_times_each_philosopher_must_eat)
			return ;
		if (philo->info->end_flag == 1)
		{
			printf("%lld %d is eating", get_time(philo, -1), philo->num);
			return ;
		}
		eating(philo, philo->info->start_time);
		if (philo->count_eat == philo->info->number_of_times_each_philosopher_must_eat)
			return ;
		sleeping(philo);
		thinking(philo);//fork cnt == 2 ? eating : waitting...
	}
}
