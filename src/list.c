/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:13:05 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 08:01:34 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_lst	*newlst(int i)
{
	pthread_mutex_t	mutex;
	t_lst			*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->num = i;
	if (pthread_mutex_init(&mutex, NULL) == -1)
		return (ft_perror("Error: mutex init fail"));
	new->fork = mutex;
	new->right = NULL;
	return (new);
}

static t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->right)
		lst = lst->right;
	return (lst);
}

static void	lstaddback(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = lstlast(*lst);
		tmp->right = new;
	}
}

static int	add_lst(t_time *time, t_lst **lst, int i)
{
	if (i != 0)
		lstaddback(lst, newlst(i + 1));
	else
	{
		*lst = newlst(i + 1);
		if (!(*lst))
			return (0);
		(*lst)->right = NULL;
	}
	return (1);
}

int	add_philo(t_time *time, t_lst **lst)
{
	t_lst		*tmp;
	int	i;

	i = -1;
	while (++i < time->number_of_philosophers)
		if (!add_lst(time, lst, i))
			return (0);
	if (i == time->number_of_philosophers)
	{
		tmp = lstlast(*lst);
		tmp->right = *lst;
	}
	return (1);
}
