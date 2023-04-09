/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/09 18:20:14 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_usleep(t_philo *philo, int now, int time)
{
	int	target;

	target = now + time;
	while (now < target)
	{
		if (philo->info->time_to_die <= now - philo->eat_time)
		{
			pthread_mutex_lock(philo->info->end_flag_mutex);
			pthread_mutex_lock(philo->info->print_mutex);
			philo->info->end_flag = 1;
			printf("%lld %d is died\n", timer(philo, 0), philo->num);
			pthread_mutex_unlock(philo->info->print_mutex);
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			return (0);
		}
		usleep(100);
		now = timer(philo, 0);
	}
	return (1);
}

static int	check_eat_cnt(t_philo *philo)
{
	pthread_mutex_lock(philo->info->end_flag_mutex);
	if (philo->eat_cnt == philo->info->must_eat && philo->info->end_flag == -1)
	{
		pthread_mutex_unlock(philo->info->end_flag_mutex);
		pthread_mutex_lock(philo->info->full_cnt_mutex);
		philo->info->full_cnt++;
		pthread_mutex_unlock(philo->info->full_cnt_mutex);
		return (0);
	}
	pthread_mutex_unlock(philo->info->end_flag_mutex);
	return (1);
}

static int	eating(t_philo *philo)
{
	int	now;

	pthread_mutex_lock(&philo->info->fork[philo->num - 1]);
	if (!print_mutex("has taken a fork\n", timer(philo, 0), philo))
		return (0);
	pthread_mutex_lock(&philo->info->fork[(philo->num) % \
	philo->info->number_of_philosophers]);
	if (!print_mutex("has taken a fork\n", timer(philo, 0), philo))
		return (0);
	now = timer(philo, 0);
	philo->eat_time = now;
	philo->eat_cnt++;
	if (!print_mutex("is eating\n", now, philo))
		return (0);
	if (!ft_usleep(philo, now, philo->info->time_to_eat))
		return (0);
	pthread_mutex_unlock(&philo->info->fork[philo->num - 1]);
	pthread_mutex_unlock(&philo->info->fork[(philo->num) % \
	philo->info->number_of_philosophers]);
	if (!check_eat_cnt(philo))
		return (0);
	return (1);
}

static void	philos_cycle(t_philo *philo)
{
	if (philo->info->must_eat == 0)
		return ;
	if (philo->num % 2 == 1)
		ft_usleep(philo, timer(philo, 0), 3);
	while (1)
	{
		printf("end_flag %d\n", philo->info->end_flag);
		if (!check_mutex_end_flag(philo->info) || !eating(philo))
			break ;
		if (!print_mutex("is sleeping\n", timer(philo, 0), philo))
			break ;
		if (!ft_usleep(philo, timer(philo, 0), philo->info->time_to_sleep))
			break ;
		if (!print_mutex("is thinking\n", timer(philo, 0), philo))
			break ;
	}
}

int	philos_born(t_philo *philo)
{
	int	i;

	philo->info->start_time = timer(philo, 1);
	i = -1;
	while (++i < philo->info->number_of_philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, (void *)philos_cycle, \
		(t_philo *)&philo[i]) != 0)
		{
			ft_perror("Error: Thread creation failed.");
			return (0);
		}
	}
	return (1);
}
