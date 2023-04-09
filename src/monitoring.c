/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:20 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/09 14:28:53 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_mutex_destroy(philo->info->fork);
	pthread_mutex_destroy(philo->info->end_flag_mutex);
	pthread_mutex_destroy(philo->info->print_mutex);
	pthread_mutex_destroy(philo->info->eat_cnt_mutex);
}
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
				printf("h1h1h1h1eat_cnt: %d\n", philo->eat_cnt);
				break ;
			}
			pthread_mutex_unlock(philo->info->eat_cnt_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->info->end_flag_mutex);
	}
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_join(philo[i].tid, NULL);
	return (0);
}
