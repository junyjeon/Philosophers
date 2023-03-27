/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:59:51 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/27 13:09:45 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"
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

typedef struct s_philo
{
	int	n_philo;
	int	l_fork;
	int	r_fork;
}		t_philo;

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
