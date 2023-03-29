/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 04:33:30 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philosophers(int ac, char **ar)
{
	struct timeval	mytime;
	t_time			time;
	t_lst			**lst;

	if (!parse(&time, lst, ac, ar))
		return (0);
	gettimeofday(&mytime, NULL);
	//add_thread();
	//time_to_spend();
	return (1);
}

int	main(int ac, char **ar)
{
	if (ac != 5 && ac != 6)
		return (ft_perror("Error: argv"));
	if (!philosophers(ac, ar))
		return (1);
	return (0);
}
