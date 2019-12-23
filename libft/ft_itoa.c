/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 19:54:48 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:15:13 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		sq10(int div)
{
	int i;

	i = 0;
	if (div == 0)
		return (1);
	while (div != 0)
	{
		div = div / 10;
		i++;
	}
	return (i);
}

static void		fill_next(char ch, int *co, char *ret)
{
	ret[*co] = ch;
	(*co)++;
}

static void		ft_itoa_rec(int n, char *ret, int *co)
{
	if (n == -2147483648)
	{
		fill_next('-', co, ret);
		fill_next('2', co, ret);
		ft_itoa_rec(147483648, ret, co);
	}
	else if (n < 0)
	{
		fill_next('-', co, ret);
		ft_itoa_rec(-n, ret, co);
	}
	else if (n > 9)
	{
		ft_itoa_rec(n / 10, ret, co);
		ft_itoa_rec(n % 10, ret, co);
	}
	else
		fill_next(n + '0', co, ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		co;

	co = 0;
	ret = (char *)malloc(sq10(n) + 1 + (n < 0));
	if (ret == NULL)
		return (ret);
	ft_itoa_rec(n, ret, &co);
	fill_next('\0', &co, ret);
	return (ret);
}
