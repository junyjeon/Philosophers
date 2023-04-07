/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:20 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/07 17:39:30 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	monitoring(t_philo *philo)
{
	int	i;

	while (1)
	{
		if (philo->info->end_flag == 1)
		{
			i = -1;
			while (++i < philo->info->number_of_philosophers)
				pthread_join(philo[i].tid, NULL);
			pthread_detach(philo->tid);
			pthread_mutex_destroy(philo->info->fork);
			break;
		}
	}
}
