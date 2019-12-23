/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 18:17:40 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:20:33 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	int		jlen;

	if (!s1 || !s2)
		return (0);
	jlen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	jstr = (char *)malloc(jlen + 1);
	if (jstr == NULL)
		return (0);
	ft_strlcpy(jstr, s1, jlen + 1);
	ft_strlcat(jstr, s2, jlen + 1);
	return (jstr);
}
