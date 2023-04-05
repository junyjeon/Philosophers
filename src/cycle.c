/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/05 19:30:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(t_philo *philo, int time_flag)
{
	struct timeval	mytime;
	long long		curr_time;
	long long		ret;

	if (gettimeofday(&mytime, NULL) == -1)
		return (ft_perror("Error: It points to areas where tv or tz cannot access."));
	curr_time = mytime.tv_sec * 1000;
	curr_time += mytime.tv_usec / 1000;
	if (time_flag)
		return (curr_time); 
	ret = curr_time - philo->eat_time;
	return (ret);
}

int	ft_usleep(t_philo *philo, long long current_time, int time_to_spend)
{
	long long	target;

	target = current_time + time_to_spend;
	while (current_time < target)
	{
		if (philo->info->time_to_die <= current_time - philo->info->start_time)
		{
			printf("%lld %d is died\n", current_time - philo->info->start_time, philo->num);
			return (0);
		}	//whatchman님 프로세스 종료시켜주세요.
		usleep(1000);
		current_time = get_time(philo, CURRENT_TIME);
	}
	return (1);
}

static int	eating(t_philo *philo, long long start_time, long long current_time)
{
	pthread_mutex_lock(&philo->lfork);
	printf("%lld %d has taken a left fork\n", current_time - start_time, philo->num);
	pthread_mutex_lock(&philo->rfork);
	printf("%lld %d has taken a right fork\n", current_time - start_time, philo->num);
	printf("%lld %d is eating\n", current_time - start_time, philo->num);
	philo->cnt_eat++;
	if (ft_usleep(philo, current_time, philo->info->time_to_eat))
		return (0);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(&philo->rfork);
	return (1);
}

static void	check(int error_num)
{
	if (error_num == 0)
		return ;
	else if (error_num == EINVAL)
	{
		ft_perror("Error: It points to areas where tv or tz cannot access.");
		return ;
	}
	else if (error_num == EDEADLK)
	{
		ft_perror("Error: It points to areas where tv or tz cannot access.");
		return ;
	}
	else if (error_num == EBUSY)
	{
		ft_perror("Error: It points to areas where tv or tz cannot access.");
		return ;
	}
	return ;
}

void	philos_cycle(t_philo *philo)
{
	int			i;

	philo->info->start_time = get_time(philo, CURRENT_TIME);
	i = -1;
	while (1)
	{
		if (philo->cnt_eat == philo->info->must_eat)
			return ;
		if (philo->info->end_flag == 1)
			return ;
		if (eating(philo, philo->info->start_time, get_time(philo, CURRENT_TIME)))
			return ;
		if (philo->cnt_eat == philo->info->must_eat)
			return ;
		printf("%lld %d is sleeping\n", get_time(philo, CURRENT_TIME) - philo->info->start_time, philo->num);
		ft_usleep(philo, get_time(philo, CURRENT_TIME), philo->info->time_to_sleep);
		printf("%lld %d is thinking\n", get_time(philo, CURRENT_TIME) - philo->info->start_time, philo->num);
	}
}
