/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_preprod.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:07:04 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/12 18:20:05 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	specs->precision = 6;
}

char	is_in_list(char c, char *list)
{
	while (list)
	{
		if (c == *list)
			return (c);
		list++;
	}
	return (0);
}

void	flag_parser(const char **format, t_format_specs specs)
{
	while (is_in_list(**format, FLAG_LIST) == 0)
	{
		if (**format == '0')
		{
			specs.padding_ch = '0';
			specs.justify = 0;
		}
		if (**format == '-' && specs.padding_ch != '0')
			specs.justify = 1;
	}
	return ;
}

void	format_spec_parser(const char **format, t_format_specs specs)
{
	while (is_in_list(**format, CONV_LIST) == 0 && **format != '.')
	{
		
		if (is_in_list(**format, "123456789*") != 0)
		{
//			if (**format == '*')
//				va_argshit
			specs.padding = specs.padding * 10 + **format - '0';
			break;
		}
		(*format)++;
	}
	if (is_in_list(**format, CONV_LIST) != 0)
		return ;
}

int		ft_printf(const char *format, ...)
{
	t_format_specs	specs;
	va_list			args;
	int				ret;

	ret = 0;
	va_start(args, format);
	init_spec_defaults(&specs);
	while (*format)
	{
		if (*format == '%')
			format_spec_parser(&format, specs);
		write(1, format, 1);
		format++;
		// first_arg = va_arg(args, int);
	}


	va_end(args);
	return (ret);
}
