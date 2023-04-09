/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:00 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/09 13:24:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_perror(char *str)
{
	printf("%s\n", str);
	return (0);
}

long long	timer(t_philo *philo, int flag)
{
	struct timeval	mytime;
	long long		now;

	if (gettimeofday(&mytime, NULL) == -1)
		return (ft_perror("Error: tv or tz cannot access."));
	now = mytime.tv_sec * 1000;
	now += mytime.tv_usec / 1000;
	if (flag)
		return (now);
	return (now - philo->info->start_time);
}

int	ft_atoi(const char *str)
{
	long long	res;

	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str == '\0')
		return (res);
	return (-1);
	if (-2147483648 > res || res > 2147483647)
		return (-1);
	return (-1);
}
