/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:04:06 by junyojeo          #+#    #+#             */
/*   Updated: 2022/07/09 04:16:25 by junyojeo         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (srclen + 1 < dstsize)
	{
		while (i < srclen + 1)
		{
			dst[i] = src[i];
			++i;
		}
	}
	else if (dstsize != 0)
	{
		while (i + 1 < dstsize)
		{
			dst[i] = src[i];
			++i;
		}
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
