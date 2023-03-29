/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:13:53 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 07:51:06 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_lst	**parse(t_time *time, t_lst **lst, int ac, char **ar)
{
	time->number_of_philosophers = ft_atoi(ar[1]);
	if (200 < time->number_of_philosophers)
		return (NULL);
	time->fork = ft_atoi(ar[1]);
	time->time_to_die = ft_atoi(ar[2]);
	time->time_to_eat = ft_atoi(ar[3]);
	time->time_to_sleep = ft_atoi(ar[4]);
	if (ac == 6)
		time->number_of_times_each_philosopher_must_eat = ft_atoi(ar[5]);
	else
		time->number_of_times_each_philosopher_must_eat = 0;
	lst = (t_lst **)malloc(sizeof(t_lst *) * time->number_of_philosophers);
	if (!lst)
		return (NULL);
	if (!add_philo(time, lst))
		return (NULL);
	return(lst);
}
