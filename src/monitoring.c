/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:20 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	monitoring(t_philo *philo)
{
	int	i;

	if (pthread_mutex_destroy(philo->info->end_flag_mutex) != 0)
		return (ft_perror("Error: mutex destroy fail"));
	if (pthread_mutex_destroy(philo->info->print_mutex) != 0)
		return (ft_perror("Error: mutex destroy fail"));
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		if (pthread_mutex_destroy(philo->info->fork) != 0)
			return (ft_perror("Error: mutex destroy fail"));
	return (1);
}
