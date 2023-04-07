/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/07 13:20:02 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	eating(t_philo *philo)
{
	long long now;

	pthread_mutex_lock(philo->lfork);
	now = timer(philo, 0);
	printf("%lld %d has taken a left fork\n", now, philo->num);
	
	pthread_mutex_lock(philo->rfork);
	now = timer(philo, 0);
	printf("%lld %d has taken a right fork\n", now, philo->num);
	
	now = timer(philo, 0);
	philo->eat_time = now;
	philo->eat_cnt++;
	printf("%lld %d is eating\n", now, philo->num);
	if (!ft_usleep(philo, now, philo->info->time_to_eat))
		return (0);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (1);
}

static void	philos_cycle(t_philo *philo)
{
	if (philo->info->must_eat == 0)
			return ;
	if (philo->num % 2 == 1)
		ft_usleep(philo, timer(philo, 0), 2);
	while (1)
	{
		pthread_mutex_lock(philo->info->end_flag_mutex);
		if (philo->info->end_flag == 1)
		{
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			return ;
		}
		if (!eating(philo))
			return ;
		if (philo->eat_cnt == philo->info->must_eat)
			return ;
		printf("%lld %d is sleeping\n", timer(philo, 0), philo->num);
		ft_usleep(philo, timer(philo, 0), philo->info->time_to_sleep);
		printf("%lld %d is thinking\n", timer(philo, 0), philo->num);
	}
}

int	philos_born(t_philo *philo)
{
	int	i;

	philo->info->start_time = timer(philo, 1);
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
