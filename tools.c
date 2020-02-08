/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:47:05 by skhalil        #+#    #+#                */
/*   Updated: 2020/02/08 18:29:21 by skhalil       ########   odam.nl         */
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

void	write_one(char ch, t_format_specs *sp)
{
	write(1, &ch, 1);
	(sp->ret)++;
}

/* 
** Doesn't reset args, fmt and ret
*/

void	reset_sp(t_format_specs *sp)
{
	sp->just = 0;
	sp->is_pad = 0;
	sp->pad = 0;
	sp->pad_ch = ' ';
	sp->is_prec = 0;
	sp->prec = 0;
	sp->conv = 'E';
}

void	initialize_sp(t_format_specs *sp, va_list *args, char *format)
{
	reset_sp(sp);
	sp->args = args;
	sp->fmt = format;
	sp->ret = 0;
}


// 
// Dealing with numbers
//
int		ft_numlen(int n)
{
	char *num_str;

	num_str = ft_itoa(n);
	n = ft_strlen(num_str);
	free(num_str);
	return (n);
}

void	ft_putnbr_co(int n, t_format_specs *sp)
{
	if (n == -2147483648)
	{
		write_one('-', sp);
		write_one('2', sp);
		ft_putnbr_co(147483648, sp);
	}
	else if (n < 0)
	{
		write_one('-', sp);
		ft_putnbr_co(-n, sp);
	}
	else if (n > 9)
	{
		ft_putnbr_co(n / 10, sp);
		ft_putnbr_co(n % 10, sp);
	}
	else
	{
		write_one(n + '0', sp);
	}
}