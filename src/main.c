/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:23 by junyojeo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/04 20:02:38 by junyojeo         ###   ########.fr       */
=======
/*   Updated: 2023/03/31 11:34:16 by junyojeo         ###   ########.fr       */
>>>>>>> 95683735f5b78f9593d8c26b19df0d909bcc5336
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philos_born(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_create(&philo[i].tid, NULL, (void *)philos_cycle, (t_philo *)&philo[i]);
	i = -1;
	while (++i < philo->info->number_of_philosophers)
		pthread_join(philo[i].tid, NULL);
}

void	watchman(t_philo *philo)
{

}

int	philosophers(int ac, char **ar)
{
<<<<<<< HEAD
	t_info	info;
	t_philo	*philo;

	if (!init_info(&info, ac, ar))
		return (0);
	philo = init_philo(&info);
	if (!philo)
		return (0);
	philos_born(philo);
	watchman(philo);
	print_struct(&info, philo);
=======
	struct timeval	mytime;
	t_time			time;
	t_lst			**lst;

	lst = parse(&time, lst, ac, ar);
	if (!lst)
		return ((int)ft_perror("Error: parse fail"));
	if (gettimeofday(&mytime, NULL) == -1)
		return ((int)ft_perror("Error: It points to areas where tv or tz cannot access."));
	
	//pthread_t tid;
	//tid = newthread();
	//if (tid < 0)
	//	return (ft_perror("Error: tid error"));
	printf("time->number_of_philosophers: %d\n", time.number_of_philosophers);
	printf("time.fork: %d\n", time.fork);
	printf("time.time_to_die: %d\n", time.time_to_die);
	printf("time.time_to_eat: %d\n", time.time_to_eat);
	printf("time.time_to_sleep: %d\n", time.time_to_sleep);
	printf("mytime: %ld", mytime.tv_usec);
	int i = -1;
	while (++i < time.number_of_philosophers)
	{
		printf("(*lst)->num: %d\n", (*lst)->num);
		printf("(*lst)->right: %p\n", (*lst)->right);
		(*lst) = (*lst)->right;
	}
>>>>>>> 95683735f5b78f9593d8c26b19df0d909bcc5336
	return (1);
}

int	main(int ac, char **ar)
{
	if (ac != 5 && ac != 6)
		return (ft_perror("Error: argv"));
	if (!philosophers(ac, ar))
		return (1);
	system("leaks --list -- a.out");
	return (0);
}
