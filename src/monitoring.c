/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:20 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/09 13:40:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	monitoring(t_philo *philo)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(philo->info->end_flag_mutex);
		if (philo->info->end_flag == 1)
		{
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			pthread_mutex_lock(philo->info->eat_cnt_mutex);
			if (!(philo->eat_cnt == philo->info->must_eat))
			{
				pthread_mutex_unlock(philo->info->eat_cnt_mutex);
				pthread_mutex_lock(philo->info->print_mutex);
				printf("%lld %d is died\n", timer(philo, 0), philo->num);
			}
			pthread_mutex_unlock(philo->info->eat_cnt_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->info->end_flag_mutex);
	}
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_join(philo[i].tid, NULL);
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_mutex_destroy(philo->info->fork);
	pthread_mutex_destroy(philo->info->end_flag_mutex);
	pthread_mutex_destroy(philo->info->print_mutex);
	pthread_mutex_destroy(philo->info->eat_cnt_mutex);
	return (0);
}
