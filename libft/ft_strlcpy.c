/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:36:25 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 13:57:54 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = 0;
	if (dst)
	{
		srclen = ft_strlen(src);
		if (srclen + 1 < dstsize)
			ft_memcpy(dst, src, srclen + 1);
		else if (dstsize != 0)
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (srclen);
}
