/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/10 11:19:37 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	monitoring(&info, philo);
	free_all(philo);
	return (1);
}

void a(void) {
	system("leaks philosophers");
}

int	main(int ac, char **ar)
{
	atexit(a);
	if (ac != 5 && ac != 6)
		return (ft_perror("Error: argv"));
	philosophers(ac, ar);
	return (0);
}
