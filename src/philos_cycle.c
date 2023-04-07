/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/07 15:07:00 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void print_mutex(char *str, int now, t_philo *philo)
{
	pthread_mutex_lock(philo->info->print_mutex);
	printf("%d %d %s", now, philo->num, str);
	pthread_mutex_unlock(philo->info->print_mutex);
}

static int	ft_usleep(t_philo *philo, int now, int time_to_spend)
{
	int	target;

	target = now + time_to_spend;
	while (now < target)
	{
		if (philo->info->time_to_die < now - philo->eat_time)
		{
			pthread_mutex_lock(philo->info->print_mutex);
			pthread_mutex_lock(philo->info->end_flag_mutex);
			printf("%d %d is died\n", now, philo->num);
			philo->info->end_flag = 1;
			pthread_mutex_unlock(philo->info->print_mutex);
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			return (0);
		}
		usleep(100);
		now = timer(philo, 0);
	}
	return (1);
}

static int	eating(t_philo *philo)
{
	int	now;

	now = timer(philo, 0);
	pthread_mutex_lock(philo->lfork);
	print_mutex("has taken a fork\n", now, philo);
	now = timer(philo, 0);
	pthread_mutex_lock(philo->rfork);
	print_mutex("has taken a fork\n", now, philo);
	now = timer(philo, 0);
	philo->eat_time = now;
	philo->eat_cnt++;
	print_mutex("is eating\n", now, philo);
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
		ft_usleep(philo, timer(philo, 0), philo->info->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(philo->info->end_flag_mutex);
		if (philo->info->end_flag == 1)
		{
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			return ;
		}
		pthread_mutex_unlock(philo->info->end_flag_mutex);
		if (!eating(philo))
			return ;
		if (philo->eat_cnt == philo->info->must_eat)
			return ;
		print_mutex("is sleeping\n", timer(philo, 0), philo);
		ft_usleep(philo, timer(philo, 0), philo->info->time_to_sleep);
		print_mutex("is thinking\n", timer(philo, 0), philo);
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
