/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   module_parser.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:48:23 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/15 15:28:35 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_parser(const char **format, t_format_specs *specs)
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

void	format_spec_parser(const char **format, t_format_specs specs, va_list *args)
{
	int		num;

    (*format)++;
    printf("before format: %s\n", *format);
    flag_parser(format, &specs);
    printf("format: %s\n", *format);
	while (is_in_list(**format, CONV_LIST) == 0 && **format != '.')
	{
		if (is_in_list(**format, "123456789*") != 0)
		{
			if (**format == '*')
            {
				num = va_arg(*args, int);
                printf("num: %d\n", num);
            }
			specs.padding = specs.padding * 10 + **format - '0';
			break ;
		}
		(*format)++;
	}
	if (is_in_list(**format, CONV_LIST) != 0)
		return ;
}
