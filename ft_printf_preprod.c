/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_preprod.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:07:04 by skhalil        #+#    #+#                */
/*   Updated: 2020/02/08 18:24:28 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	launch_conversion(t_format_specs *sp)
{
	int		d;
	int		start;

	start = 0;
	if (sp->conv == 'd')
	{
		d = va_arg(*(sp->args), int); 
		if (ft_numlen(d) >= sp->pad)
			ft_putnbr_co(d, sp);
		// else if (sp->precision)
		else
		{
			start = sp->ret;
			while (sp->ret - start != sp->pad - ft_numlen(d))
				write_one(sp->pad_ch, sp);
			ft_putnbr_co(d, sp);
		}
	}
}

// implement a writer function

int		ft_printf(const char *format, ...)
{
	t_format_specs	sp;
	va_list			args;

	va_start(args, format);
	initialize_sp(&sp, &args, (char *)format);
	while (*format)
	{
		if (*format == '%')
		{
			reset_sp(&sp);
			format_spec_parser(&sp);

			while (is_in_list(*(sp.fmt), "-0")) //patch for neg precision or 0 in prec
				(sp.fmt)++;

			if (sp.conv == 'E')
				return (sp.ret);
			
			launch_conversion(&sp);
		}
		else
			write_one(*(sp.fmt), &sp);
		(sp.fmt)++;
		// first_arg = va_arg(args, int);
	}
	va_end(args);
	return (sp.ret);
}
