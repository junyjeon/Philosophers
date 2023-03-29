/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:59:46 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 07:59:59 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_destory(t_time *time, t_lst **lst)
{
	t_lst	*tmp;
	int		i;

	i = -1;
	while (++i < time->number_of_philosophers)
	{
		tmp = (*lst)->right;
		if (pthread_mutex_destroy(&(*lst)->fork) != 0)
			return (ft_perror("Error: mutex destroy fail"));
		if (pthread_join((*lst)->tid, NULL) != 0)
			return (ft_perror("Error: thread destroy fail"));
		*lst = tmp;
	}
	return (1);
}
