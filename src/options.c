/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:18:38 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 08:08:15 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(struct timeval *mytime, int time_to_ms)
{
	suseconds_t	target;
	target = mytime->tv_usec + time_to_ms; 
	while (target < mytime->tv_usec)
		usleep(time_to_ms);
}

//void	sleeping(t_time *time, struct timeval *mytime)
//{
	
//}

//void	eating(t_time *time, struct timeval *mytime)
//{
//	if ()
//	{
//		fork(time);
//		ft_usleep(time->time_to_eat);
//		fork_put_down(time, i);
//	}
//}

//void	thinking(t_time *time, struct timeval *mytime)
//{
	
//}

void	*_thread(void *param)
{
	printf("Thread Created\n");
	return (NULL);
}

pthread_t	newthread(t_time *time)
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, _thread, (void *)time) < 0)
		printf("Error: thread create error");
	return (tid);
}
