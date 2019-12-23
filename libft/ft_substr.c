/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 17:55:54 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:22:10 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	subslen;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if ((unsigned int)ft_strlen((char *)s) <= start)
		return (ft_calloc(1, 1));
	subslen = ft_strlen((char *)&s[start]);
	subslen = (subslen > len) ? len : subslen;
	subs = (char *)malloc(subslen + 1);
	if (subs == NULL)
		return (NULL);
	while (s[start + i] && subslen - i != 0)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
