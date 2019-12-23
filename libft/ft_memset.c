/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:14:01 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 13:55:37 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)b;
	ch = (unsigned char)c;
	while (i < len)
	{
		str[i] = ch;
		i++;
	}
	return (b);
}
