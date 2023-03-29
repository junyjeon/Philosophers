/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:13:53 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 04:30:09 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse(t_time *time, t_lst **lst, int ac, char **ar)
{
	time->number_of_philosophers = ft_atoi(ar[1]);
	time->fork = ft_atoi(ar[1]);
	time->time_to_die = ft_atoi(ar[2]);
	time->time_to_eat = ft_atoi(ar[3]);
	time->time_to_sleep = ft_atoi(ar[4]);
	if (ac == 6)
		time->number_of_times_each_philosopher_must_eat = ft_atoi(ar[5]);
	lst = (t_lst **)malloc(sizeof(t_lst *) * time->number_of_philosophers);
	if (!lst)
		return (0);
	if (!add_philo(time, lst))
		return (0);
	//add_thread(time, lst);
	return(1);
}
