/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   module_parser.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:48:23 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/17 19:45:38 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_specs(t_format_specs *specs, char *state)
{
	printf("[%s]\n", state);
	printf("justify: %d\n", specs->justify);
	printf("padding: %d\n", specs->padding);
	printf("padding_ch: |%c|\n", specs->padding_ch);
	printf("precision: %d\n", specs->precision);
	printf("[end]\n\n");
}

void		flag_parser(const char **format, t_format_specs *specs)
{
	while (is_in_list(**format, FLAG_LIST) != 0 && **format != '.' && is_in_list(**format, CONV_LIST) == 0)
	{
		if (**format == '0')
		{
			specs->padding_ch = '0';
			specs->justify = 0;
		}
		else if (**format == '-' && specs->padding_ch != '0')
			specs->justify = 1;
		(*format)++;
	}
}

void		width_parser(const char **format, t_format_specs *specs, va_list *args)
{
	while (is_in_list(**format, CONV_LIST) == 0 && **format != '.')
	{
		if (**format == '*')
		{
			specs->padding = va_arg(*args, int);
			break ;
		}
		else if (is_in_list(**format, "1234567890") != 0)
			specs->padding = specs->padding * 10 + **format - '0';
		else
			break ;
		(*format)++;
	}
	if (**format == '.') // also check if precision hasn't been set before that
		precision_parser(format, specs, args);
}

void		precision_parser(const char **format, t_format_specs *specs, va_list *args)
{
	(*format)++;
	while (is_in_list(**format, CONV_LIST) == 0)
	{
		if (**format == '*')
		{
			specs->precision = va_arg(*args, int);
			break ;
		}
		else if (is_in_list(**format, "1234567890") != 0)
			specs->precision = specs->precision * 10 + **format - '0';
		else
			break ;
		(*format)++;
	}
}

t_format_specs	format_spec_parser(const char **format, t_format_specs specs, va_list *args)
{
	(*format)++;
	flag_parser(format, &specs);
	if (**format == '.')
		precision_parser(format, &specs, args);
	else
		width_parser(format, &specs, args);
	return (specs);
}
