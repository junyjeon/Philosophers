/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:59:46 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/31 20:25:20 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_destory(t_info *info, t_philo **philo)
{
	t_philo	*tmp;
	int		i;

	i = -1;
	while (++i < philo->number_of_philosophers)
	{
		tmp = (*philo)->right;
		if (pthread_mutex_destroy(&(*philo)->fork) != 0)
			return (ft_perror("Error: mutex destroy fail"));
		if (pthread_join((*philo)->tid, NULL) != 0)
			return (ft_perror("Error: thread destroy fail"));
		*philo = tmp;
	}
	return (1);
}
