/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   module_parser.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:48:23 by skhalil        #+#    #+#                */
/*   Updated: 2020/02/08 19:02:13 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_specs(t_format_specs *sp, char *state)
{
	printf("[%s]\n", state);
	printf("just: %d\n", sp->just);
	printf("pad: %d\n", sp->pad);
	printf("pad_ch: |%c|\n", sp->pad_ch);
	printf("prec: %d\n", sp->prec);
	printf("[end]\n\n");
}

void		flag_parser(t_format_specs *sp)
{
	while (is_in_list(*(sp->fmt), FLAG_LIST) != 0 && *(sp->fmt) != '.' && is_in_list(*(sp->fmt), CONV_LIST) == 0)
	{
		if (*(sp->fmt) == '0')
		{
			sp->pad_ch = '0';
			sp->just = 0;
		}
		else if (*(sp->fmt) == '-' && sp->pad_ch != '0')
			sp->just = 1;
		(sp->fmt)++;
	}
}

void		width_parser(t_format_specs *sp)
{
	while (is_in_list(*(sp->fmt), CONV_LIST) == 0 && *(sp->fmt) != '.')
	{
		if (*(sp->fmt) == '*')
		{
			sp->pad = va_arg(*(sp->args), int);
			break ;
		}
		else if (is_in_list(*(sp->fmt), "1234567890") != 0)
			sp->pad = sp->pad * 10 + *sp->fmt - '0'; //use atoi for that
		else
			break ;
		(sp->fmt)++;
	}
	if (*(sp->fmt) == '.')		// also check if prec hasn't been set before that
		precision_parser(sp);
}

void		precision_parser(t_format_specs *sp)
{
	(sp->fmt)++;
	while (is_in_list(*(sp->fmt), CONV_LIST) == 0)
	{
		if (*(sp->fmt) == '*')
		{
			sp->prec = va_arg(*(sp->args), int);
			break ;
		}
		else if (is_in_list(*(sp->fmt), "1234567890") != 0)
			sp->prec = sp->prec * 10 + *sp->fmt - '0';
		else
			break ;
		(sp->fmt)++;
	}
}

void		format_spec_parser(t_format_specs *sp)
{
	(sp->fmt)++;
	flag_parser(sp);
	if (*(sp->fmt) == '.')
		precision_parser(sp);
	else
		width_parser(sp);
	if (is_in_list(*(sp->fmt), CONV_LIST) != 0)
		sp->conv = *(sp->fmt);
}
