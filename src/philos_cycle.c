/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/07 09:50:24 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	eating(t_philo *philo)
{
	long long time;
	pthread_mutex_lock(philo->lfork);
	printf("%lld %d has taken a left fork\n", timer() - philo->info->start_time, philo->num);
	
	pthread_mutex_lock(philo->rfork);
	printf("%lld %d has taken a right fork\n", timer() - philo->info->start_time, philo->num);
	
	time = timer();
	philo->eat_time = time;
	philo->cnt_eat++;
	
	pthread_mutex_lock(philo->info->start_time_mutex);
	printf("%lld %d is eating\n", time - philo->info->start_time, philo->num);
	pthread_mutex_unlock(philo->info->start_time_mutex);
	if (!ft_usleep(philo, time, philo->info->time_to_eat))
		return (0);
	
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (1);
}

static void	philos_cycle(t_philo *philo)
{

	philo->eat_time = philo->info->start_time;
	if (philo->num % 2 == 1)
		ft_usleep(philo, timer(), 1);
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
		pthread_mutex_lock(philo->info->start_time_mutex);
		printf("%lld %d is sleeping\n", timer() - philo->info->start_time, philo->num);
		pthread_mutex_unlock(philo->info->start_time_mutex);
		ft_usleep(philo, timer(), philo->info->time_to_sleep);
		pthread_mutex_lock(philo->info->start_time_mutex);
		printf("%lld %d is thinking\n", timer() - philo->info->start_time, philo->num);
		pthread_mutex_unlock(philo->info->start_time_mutex);
	}
}

int	philos_born(t_philo *philo)
{
	int	i;

	philo->info->start_time = timer();
	i = -1;
	while (++i < philo->info->number_of_philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, (void *)philos_cycle, (t_philo *)&philo[i]) != 0)
		{
			ft_perror("Error: Thread creation failed.");
			return (0);
		}
	}
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_join(philo[i].tid, NULL);
	return (1);
}
//공유 자원 사용하는 곳 뮤텍스 걸기, 1ms 해결하기
