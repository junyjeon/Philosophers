/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 03:25:06 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers(int ac, char **ar)
{
	struct timeval	mytime;
	t_time			time;
	t_lst			**lst;

	parse(&time, lst, ac, ar);
	gettimeofday(&mytime, NULL);
	//add_thread();
	//time_to_spend();
}

int	main(int ac, char **ar)
{
	if (ac != 5 && ac != 6)
		return (ft_perror("Error: argv"));
	philosophers(ac, ar);
	return (0);
}
