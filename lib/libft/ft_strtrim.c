/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 05:03:26 by junyojeo          #+#    #+#             */
/*   Updated: 2022/08/03 20:23:27 by junyojeo         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_front(char const *s1, char const *set)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (!ft_find(s1[i], set))
			return (i);
	}
	return (-1);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (--i)
	{
		if (!ft_find(s1[i], set))
			return (i);
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	if (ft_front(s1, set) == -1 && ft_end(s1, set) == -1)
		return (ft_strdup(""));
	str = ft_substr(s1, ft_front(s1, set), \
	ft_end(s1, set) - ft_front(s1, set) + 1);
	return (str);
}
