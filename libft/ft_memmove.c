/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:31:06 by skhalil        #+#    #+#                */
/*   Updated: 2019/11/30 20:31:13 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	size_t			i;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		while (i != len)
		{
			dst_p[i] = src_p[i];
			i++;
		}
	else
		while (len != 0)
		{
			dst_p[len - 1] = src_p[len - 1];
			len--;
		}
	return (dst);
}
