/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 19:22:19 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:21:06 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (s1[i] == '\0' || s2[i] == '\0' || ret != 0)
			return (ret);
		i++;
	}
	return (ret);
}
