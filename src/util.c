/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:00 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/04 23:12:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_perror(char *str)
{
	printf("%s\n", str);
	return (0);
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
	printf("get_time: %lld\n", get_time(philo, get_time(philo, 0)));
	int i = -1;
	while (++i < info->number_of_philosophers)
	{
		printf("philo->num: %d\n", philo[0].num);
		// printf("philo[i].tid: %d\n", philo[i].tid);
		printf("philo[i].cnt_eat: %d\n", philo[i].cnt_eat);
		printf("philo[i].eat_start_time: %lld\n", philo[i].eat_time);
		printf("philo[i].info: %p\n", philo[i].info);
	}
	return (1);
}
