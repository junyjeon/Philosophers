/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:00 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 04:29:37 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_perror(char *str)
{
	printf("%s\n", str);
	return (0);
}

t_lst	*newlst(int tid)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->tid = tid;
	new->fork = 1;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_lst	*lstlast(t_lst *lst)
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

int	add_philo(t_time *time, t_lst **lst)
{
	int		tid;
	t_lst	*tmp;
	int	i;

	i = -1;
	while (++i < time->number_of_philosophers)
	{
		tid = newthread();
		if (!tid)
			return (ft_perror("Error: tid error"));
		lstaddback(lst, newlst(tid));
	}
	if (i == time->number_of_philosophers)
	{
		tmp = lstlast(*lst);
		tmp->right = *lst; 
	}
	return (1);
}
