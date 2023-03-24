/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:51 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/23 18:46:37 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philosophers
{
	int	l_fork;
	int	r_fork;
}		t_philosophers;

typedef struct s_state
{
	int	eat;
	int	think;
	int	sleep;
}		t_state;

typedef struct s_time
{
	int	number_of_philosophers;
	int	fork;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}		t_time;

#endif