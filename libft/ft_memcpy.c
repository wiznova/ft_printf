/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 19:43:08 by skhalil        #+#    #+#                */
/*   Updated: 2019/11/30 20:25:38 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	size_t			i;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	i = 0;
	if (dst_p == NULL && src_p == NULL)
		return (dst);
	while (i < n)
	{
		dst_p[i] = src_p[i];
		i++;
	}
	return (dst);
}
