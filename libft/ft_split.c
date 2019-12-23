/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 18:11:56 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:20:15 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	howmany(char const *s, char c)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			ret++;
		while (s[i] != c && s[i])
			i++;
	}
	return (ret);
}

static int	fill(char const *s, char c, char ***ret)
{
	int		start;
	int		i;
	int		ret_i;

	start = 0;
	i = 0;
	ret_i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			(*ret)[ret_i] = ft_substr(s, start, i - start);
			if ((*ret)[ret_i] == NULL)
				return (ret_i);
			ret_i++;
		}
	}
	(*ret)[ret_i] = NULL;
	return (-1);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		mfail;

	if (!s)
		return (0);
	ret = (char **)malloc(sizeof(char *) * howmany(s, c) + sizeof(char *));
	if (ret == NULL)
		return (NULL);
	mfail = fill(s, c, &ret);
	if (mfail != -1)
	{
		mfail--;
		while (mfail > 0)
		{
			free(ret[mfail]);
			mfail--;
		}
		if (mfail == 0)
			free(ret);
		ret = NULL;
	}
	return (ret);
}
