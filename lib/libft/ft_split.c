/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:48:13 by marvin            #+#    #+#             */
/*   Updated: 2023/03/14 03:52:55 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c, size_t i)
{
	size_t	cnt;

	cnt = 0;
	while (s[i] != c)
	{
		if (!s[i])
			break ;
		cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_free(char **res)
{
	size_t	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}

static char	**ft_division(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;

	j = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i] == '\0')
				return (res);
			res[++j] = ft_substr(s, i, word_len(s, c, i));
			if (!res[j])
			{
				ft_free(res);
				return (NULL);
			}	
			i = i + word_len(s, c, i);
		}
		else
			i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_cnt;
	char	**res;

	word_cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word_cnt++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (0);
	res = ft_division(s, c, res);
	if (res == NULL)
		return (NULL);
	res[word_cnt] = NULL;
	return (res);
}
