/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/23 18:51:22 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_perror(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

void	parse(t_time *time, char **ar)
{
	time->number_of_philosophers = ft_atoi(ar[1]);
	time->fork = ft_atoi(ar[1]);
	time->time_to_die = ft_atoi(ar[2]);
	time->time_to_eat = ft_atoi(ar[3]);
	time->time_to_sleep = ft_atoi(ar[4]);
	time->number_of_times_each_philosopher_must_eat = ft_atoi(ar[5]);
}

void	philosophers(t_time *time, char **ar)
{
	struct timeval mytime;

	parse(time, ar);
	gettimeofday(&mytime, NULL);
}

int	main(int ac, char **ar)
{
	t_time time;

	if (ac < 4 || 5 < ac)
		ft_perror("Error: argv ");
	philosophers(&time, ar);
	if (ac == 5)
	
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