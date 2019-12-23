/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 20:00:01 by skhalil        #+#    #+#                */
/*   Updated: 2019/11/30 20:10:59 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	unsigned char	ch;
	size_t			i;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i != n)
	{
		dst_p[i] = src_p[i];
		if (dst_p[i] == ch)
			return ((void *)&dst_p[i + 1]);
		i++;
	}
	return (NULL);
}
