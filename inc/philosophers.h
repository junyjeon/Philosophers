/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:51 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/09 16:37:45 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				end_flag;
	int				full_cnt;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*end_flag_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*full_cnt_mutex;
	long long		start_time;
}		t_info;

typedef struct s_philo
{
	int				num;
	pthread_t		tid;
	int				eat_cnt;
	long long		eat_time;
	t_info			*info;
}		t_philo;

typedef struct s_state
{	
	int	eat;
	int	think;
	int	sleep;
}		t_state;

/* init */
int			init_info(t_info *info, int ac, char **ar);
t_philo		*init_philo(t_info *info);

/* born */
int			philos_born(t_philo *philo);
void		monitoring(t_info *info);
int			check_mutex_end_flag(t_info *info);

/* util */
int			print_mutex(char *str, int now, t_philo *philo);
long long	timer(t_philo *philo, int flag);
void		free_all(t_philo *philo);
int			ft_atoi(const char *str);
int			ft_perror(char *str);

#endif
