/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:00 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/06 17:33:13 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_perror(char *str)
{
	printf("%s\n", str);
	return (0);
}

long long	get_time(t_philo *philo)
{
	struct timeval	mytime;
	long long		curr_time;
	long long		ret;

	if (gettimeofday(&mytime, NULL) == -1)
		return (ft_perror("Error: It points to areas where tv or tz cannot access."));
	curr_time = mytime.tv_sec * 1000;
	curr_time += mytime.tv_usec / 1000;
	return (curr_time);
}

int	ft_usleep(t_philo *philo, long long current_time, int time_to_spend)
{
	long long	target;

	target = current_time + time_to_spend;
	while (current_time < target)
	{
		// 수명 <= 현재시각 - 마지막으로 밥먹은시각
		if (philo->info->time_to_die <= current_time - philo->eat_time)
		{
			printf("%lld %d is died\n", current_time - philo->info->start_time, philo->num);
			pthread_mutex_lock(philo->info->end_flag_mutex);
			philo->info->end_flag = 1;
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			return (0);
		}
		usleep(50);
		current_time = get_time(philo);
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

int	print_struct(t_info *info, t_philo *philo)
{
	struct timeval	mytime;

	printf("info->number_of_philosophers: %d\n", info->number_of_philosophers);
	//printf("fork: %d\n", fork);
	printf("info->time_to_die: %d\n", info->time_to_die);
	printf("info->time_to_eat: %d\n", info->time_to_eat);
	printf("info->time_to_sleep: %d\n", info->time_to_sleep);
	printf("info->must_eat: %d\n", info->must_eat);
	printf("info->end_flag: %d\n", info->end_flag);
	//printf("info->end_flag_mutex: %d\n", info->end_flag_mutex);
	printf("info->start_time: %lld\n", info->start_time);
	
	if (gettimeofday(&mytime, NULL) == -1)
		return (ft_perror("Error: It points to areas where tv or tz cannot access."));
	//printf("get_time: %lld\n", get_time(philo)));
	int i = -1;
	while (++i < info->number_of_philosophers)
	{
		printf("philo->num: %d\n", philo[i].num);
		// printf("philo[i].tid: %d\n", philo[i].tid);
		printf("philo[i].cnt_eat: %d\n", philo[i].cnt_eat);
		printf("philo[i].eat_start_time: %lld\n", philo[i].eat_time);
		printf("philo[i].info: %p\n", philo[i].info);
	}
	return (1);
}
