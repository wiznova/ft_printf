/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:24:14 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:10:54 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strnlen(dst, dstsize);
	if (dstsize < len)
		return (len + ft_strlen(src));
	return (len + ft_strlcpy(dst + len, src, dstsize - len));
}
