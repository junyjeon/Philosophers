/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:07:30 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 15:54:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_addnum(int n, char *str, int len)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[len - 1] = '8';
			len--;
			n = 214748364;
		}
		else
			n *= -1;
	}
	else if (n == 0)
		str[0] = '0';
	while (len && n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

static size_t	ft_get_n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147473648)
			return (10);
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	char	*str;

	if (!n)
		return (ft_strdup("0"));
	n_len = ft_get_n_len(n);
	str = (char *)malloc(n_len + 1);
	if (!str)
		return (NULL);
	ft_addnum(n, str, n_len);
	return (str);
}
