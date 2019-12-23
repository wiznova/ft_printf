/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:34:41 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 13:54:22 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (n != 0)
	{
		str = (char *)s;
		while (i != n)
		{
			str[i] = '\0';
			i++;
		}
	}
}
