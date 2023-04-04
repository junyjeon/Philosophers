/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/04 20:02:38 by junyojeo         ###   ########.fr       */
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
