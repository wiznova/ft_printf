/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_preprod.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:07:04 by skhalil        #+#    #+#                */
/*   Updated: 2020/02/13 16:06:37 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO:
// parser: incorporate atoi, assign boolean values (is_pad, is_prec)
//

void	conversion_d(t_format_specs *sp)
{
	int		d;
	int		start;

	start = 0;
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

void	conversion_c(t_format_specs *sp)
{
	int		i;

	i = 0;
	if (sp->is_pad == 0 && sp->is_prec == 0)
		write_one(sp->na.c, sp);
	if (sp->is_pad == 1 && sp->is_prec == 0)
	{
		if (sp->just == 0)
		{
			while (i < sp->pad - 1)
			{
				write_one(sp->pad_ch, sp);
				i++;
			}
			write_one(sp->na.c, sp);
		}
		else
		{
			write_one(sp->na.c, sp);
			while (i < sp->pad - 1)
			{
				write_one(sp->pad_ch, sp);
				i++;
			}
		}
	}
	// if (sp->is_pad == 0 && sp->is_prec == 1)
	// if (sp->is_pad == 1 && sp->is_prec == 1)
}

void	launch_conversion(t_format_specs *sp, char conv)
{
	if (conv == 'd')
		conversion_d(sp);
	else if (conv == 'c')
		conversion_c(sp);
}

void	get_next_argument(t_format_specs *sp)
{
	if (sp->conv == 'c')
		sp->na.c = (char)va_arg(*(sp->args), int);
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
			get_next_argument(&sp);
			launch_conversion(&sp, sp.conv);
		}
		else
			write_one(*(sp.fmt), &sp);
		(sp.fmt)++;
	}
	va_end(args);
	return (sp.ret);
}
