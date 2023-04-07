/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:13:53 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/07 15:37:41 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutex(t_info *info)
{
	int	i;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->number_of_philosophers);
	if (!info->fork)
		return (ft_perror("Error: EINVAL_00"));
	i = -1;
	while (++i < info->number_of_philosophers)
		if (pthread_mutex_init(&info->fork[i], NULL) == -1)
			return (ft_perror("Error: EINVAL_01"));
	info->end_flag_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(info->end_flag_mutex, NULL) == -1)
		return (ft_perror("Error: EINVAL_02"));
	info->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(info->print_mutex, NULL) == -1)
		return (ft_perror("Error: EINVAL_03"));
	return (1);
}

int	init_info(t_info *info, int ac, char **ar)
{
	info->number_of_philosophers = ft_atoi(ar[1]);
	if (info->number_of_philosophers == 0 || 200 < info->number_of_philosophers)
		return (ft_perror("Error: number_of_philosophers"));
	info->time_to_die = ft_atoi(ar[2]);
	info->time_to_eat = ft_atoi(ar[3]);
	info->time_to_sleep = ft_atoi(ar[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(ar[5]);
	else
		info->must_eat = -1;
	info->end_flag = -1;
	init_mutex(info);
	return (1);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (!philo)
	{
		ft_perror("Error: parse fail");
		return (NULL);
	}
	i = -1;
	while (++i < info->number_of_philosophers)
	{
		philo[i].num = i + 1;
		philo[i].lfork = &info->fork[i];
		philo[i].rfork = &info->fork[(i + 1) % info->number_of_philosophers];
		philo[i].eat_cnt = 0;
		philo[i].eat_time = 0;
		philo[i].info = info;
	}
	return (philo);
}
