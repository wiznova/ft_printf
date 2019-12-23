/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:42:56 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 13:49:01 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	co;

	i = 0;
	co = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (needle[co] == haystack[i + co] && needle[co]
		&& (i + co) < len)
			co++;
		if (len - i - co == 0 && needle[co] != 0)
			return (0);
		else if (needle[co] == 0)
			return ((char *)&haystack[i]);
		co = 0;
		i++;
	}
	return (0);
}
