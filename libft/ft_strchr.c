/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:18:41 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 13:52:18 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*ret;
	char	letter;

	letter = (char)c;
	i = 0;
	while (str[i] != letter && str[i] != '\0')
		i++;
	ret = (char *)&str[i];
	if (letter == '\0')
		return (ret);
	else if (str[i] == '\0')
		return (0);
	return (ret);
}
