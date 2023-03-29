/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 04:34:34 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//void	ft_usleep(struct timeval *mytime, int time_to_ms)
//{
//	suseconds_t	target;
//	target = timeval->tv_usec + time_to_ms; 
//	while (target < timeval->tv_usec)
//		usleep(time_to_ms);
//}

//void	sleeping(t_time *time, struct timeval *mytime)
//{
	
//}

//void	eating(t_time *time, struct timeval *mytime)
//{
//	if ()
//	{
//		fork_get(time);
//		ft_usleep(time->time_to_eat);
//		fork_put_down(time, i);
//	}
//}

//void	thinking(t_time *time, struct timeval *mytime)
//{
	
//}

void	*thread()
{
	printf("tid: , Thread Created");
	return (NULL);
}

int	newthread()
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, thread, NULL) < 0)
		return (ft_perror("Error: thread create error"));
	return ((int)tid);
}
