/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:51 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/04 23:35:53 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../lib/libft/libft.h"
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

/* 시간 */
//현재 시간을 가져오고 시스템 시간을 설정 int gettimeofday(struct timeval *tv, struct timezone *tz);
/* 프로세스 */
//쓰레드 생성 int pthread_create(pthread_t *thread, pthread_attr_t *attr, void * (*start_routine)(void *), void * arg);
//쓰레드를 분리 상태로 만듬 int pthread_detach(pthread_t th);
//쓰레드가 종료되는 걸 기다림 int pthread_join(pthread_t th, void **thread_return);
/* 뮤텍스 */
//뮤텍스 초기화 int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutex_attr *attr);
//뮤텍스 파기 및  초기화 int pthread_mutex_destroy(pthread_mutex_t *mutex);
//뮤텍스를 잠금 int pthread_mutex_lock(pthread_mutex_t *mutex);
//int pthread_mutex_trylock(pthread_mutex_t *mutex);
//뮤텍스 해제int pthread_mutex_unlock(pthread_mutex_t *mutex);
//int pthread_mutex_destroy(pthread_mutex_t *mutex);
//프로그램 실행중에  쓰레드 생성하기. tmp philo 갖고있기
//시간
//목표시간 = 현재시간 - 먹기 시작한 시간.
# define CURRENT_TIME	1

typedef struct s_info
{
	int				number_of_philosophers;
	pthread_mutex_t	*fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				end_flag;
	pthread_mutex_t	end_flag_mutex;
	long long		start_time;
}		t_info;

typedef struct s_philo
{
	int				num;
	pthread_t		tid;
	pthread_mutex_t	lfork;
	pthread_mutex_t	rfork;
	int				cnt_eat;
	long long		eat_time;
	t_info			*info;
}		t_philo;

typedef struct s_state
{
	int	eat;
	int	think;
	int	sleep;
}		t_state;

/* main */

/* init */
int			init_info(t_info *info, int ac, char **ar);
t_philo		*init_philo(t_info *info);

/* options */
void		philos_cycle(t_philo *philo);

/* mutex */
//int			mutex_destory(t_info *info, t_philo **philo);

/* util */
int			ft_perror(char *str);
int			print_struct(t_info *info, t_philo *philo);
int			ft_usleep(t_philo *philo, long long current_time, int time_to_spend);
long long	get_time(t_philo *philo, int flag);

#endif

// ar[1] = number_of_philosophers
// fork = number_of_philosophers;
// fork는 lock되어야 한다. 뮤텍스
// ar[2] = time_to_die
// 되면 죽는 시간
// ar[3] = time_to_eat
// 먹는 시간
// ar[4] = time_to_sleep
// 잠을 자는 시간
// ar[5] = must_eat
// 철학자들이 모두 eat를 채우면 종료

// phil의 왼쪽 오른쪽 포크
// 스레드 생성시 4번째 매개변수로 구조체 전달 후 tid 넣어두면 됨
