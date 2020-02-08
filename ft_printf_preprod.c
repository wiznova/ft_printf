/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_preprod.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:07:04 by skhalil        #+#    #+#                */
/*   Updated: 2020/02/08 19:23:33 by skhalil       ########   odam.nl         */
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
		// else if (sp->precision) //what is this supposed to do?
		else
		{
			start = sp->ret;
			while (sp->ret - start != sp->pad - ft_numlen(d))
				write_one(sp->pad_ch, sp);
			ft_putnbr_co(d, sp);
		}
	}
}

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

			if (sp.conv == 'E') // check if conversion is missing or not supported
				return (sp.ret);// check return value of libc printf for that 
			
			launch_conversion(&sp);
		}
		else
			write_one(*(sp.fmt), &sp);
		(sp.fmt)++;
	}
	va_end(args);
	return (sp.ret);
}
