/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/27 13:00:35 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(1);
}

void	parse(t_time *time, int ac, char **ar)
{
	time->number_of_philosophers = ft_atoi(ar[1]);
	time->fork = ft_atoi(ar[1]);
	time->time_to_die = ft_atoi(ar[2]);
	time->time_to_eat = ft_atoi(ar[3]);
	time->time_to_sleep = ft_atoi(ar[4]);
	if (ac == 5)
		time->number_of_times_each_philosopher_must_eat = ft_atoi(ar[5]);
}

t_philo	ft_add_philo(t_time *time, int i);
{
	pthread_t	thread_t;
	int	a = 100;
	int	status;
	
	if (pthread_create(&thread_t, NULL, func, (void *)&a) < 0)
		ft_perror("thread create error:");
	pthread_join(thread_t, (void **)&status);
	t_philo
	int	i;
	
	i = 0;
	while (i < time->number_of_philosophers)
		ft_lstnew(pthread_create(i, ));
}

void	philosophers(t_time *time, int ac, char **ar)
{
	struct timeval	mytime;
	int				i;

	parse(time, ac, ar);
	i = -1;
	while (++i < time->number_of_philosophers)
	{
		ft_add_philo(time);
	}
	gettimeofday(&mytime, NULL);
	
	pthread_create(thread, pthread_attr_t ,start_routine, arg);
	
}

int	main(int ac, char **ar)
{
	t_time	time;

	if (ac < 4 || 5 < ac)
		ft_perror("Error: argv ");
	philosophers(&time, ac, ar);
	return (0);
}

// ar[1] = number_of_philosophers
// fork = number_of_philosophers;
// fork는 lock되어야 한다. 뮤텍스
// ar[2] = time_to_die
// 되면 죽는 시간
// ar[3] = time_to_eat
// 먹는 시간
// ar[4] = time_to_sleep
// 잠을 자는 시간
// ar[5] = number_of_times_each_philosopher_must_eat
// 철학자들이 모두 eat를 채우면 종료

// ./fdf 1 2 3 4 5

// 철학자들의 수는 200까지
// 철학자는 1번부터
