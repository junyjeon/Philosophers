/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:00 by junyojeo          #+#    #+#             */
/*   Updated: 2023/03/30 03:32:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_perror(char *str)
{
	printf("%s\n", str);
	return (1);
}

static t_lst	*newlst(int i)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	new->fork = 1;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

static t_lst *lstlast(t_lst *lst)
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

	if (!*lst)
		*lst = new;
	else
	{
		tmp = lstlast(*lst);
		tmp->right = new;
	}
}

void	add_philo(t_time *time, t_lst **lst)
{
	int	i;

	i = -1;
	while (++i < time->number_of_philosophers)
		lstaddback(lst, newlst(i));
}
