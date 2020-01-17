/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_preprod.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:07:04 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/17 20:04:57 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*
**	TODO:
**	finish parser --> parse flags, width (incl *), [.precision] (incl *), and finally conversion
**	check if va_arg is working from a function higher on a stack
**	choose conversion function, write a selector function
**
 */

void	init_spec_defaults(t_format_specs *specs)
{
	specs->justify = 0;
	specs->padding = 0;
	specs->padding_ch = ' ';
	specs->precision = 0;
}

void	launch_conversion(char conv, t_format_specs *temp_specs, va_list *args)
{
	int		d;

	if (conv == 'd')
	{
		d = va_arg(*args, int);
		ft_putnbr_fd(d, 1);
	}
	temp_specs->padding = 0;
}

int		ft_printf(const char *format, ...)
{
	t_format_specs	specs;
	t_format_specs	temp_specs;
	va_list			args;
	int				ret;

	ret = 0;
	va_start(args, format);
	init_spec_defaults(&specs);
	while (*format)
	{
		if (*format == '%')
		{
			temp_specs = format_spec_parser(&format, specs, &args);
			if (is_in_list(*format, CONV_LIST) != 0)
				launch_conversion(*format, &temp_specs, &args);
		}
		else
			write(1, format, 1);
		format++;
		// first_arg = va_arg(args, int);
	}
	va_end(args);
	return (ret);
}
