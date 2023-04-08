/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:20 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/08 16:12:12 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	monitoring(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->info->end_flag_mutex);
		if (philo->info->end_flag == 1)
		{
			pthread_mutex_unlock(philo->info->end_flag_mutex);
			pthread_mutex_lock(philo->info->print_mutex);
			printf("%d %d is died\n", timer(philo, 0), philo->num);
			break ;
		}
		pthread_mutex_unlock(philo->info->end_flag_mutex);
	}
	return (0);
}
