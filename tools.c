/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:47:05 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/15 15:18:15 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_in_list(char c, char *list)
{
	while (*list)
	{
		if (c == *list)
			return (c);
		list++;
	}
	return (0);
}