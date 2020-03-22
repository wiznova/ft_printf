/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   module_parser.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:48:23 by skhalil        #+#    #+#                */
/*   Updated: 2020/03/12 18:53:23 by skhalil       ########   odam.nl         */
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
	char	cur_c;

	cur_c = *(sp->fmt);
	while (is_in_list(cur_c, FLAG_LIST)) //deleted:  && not_in_list(cur_c, CONV_LIST) && cur_c != '.')
	{
		if (cur_c == '0')
		{
			sp->pad_ch = '0';
			sp->just = RIGHT;
		}
		else if (cur_c == '-' && sp->pad_ch == ' ')
			sp->just = LEFT;
		(sp->fmt)++;
		cur_c = *(sp->fmt);
	}
}

void		offset(t_format_specs *sp)
{
	char	cur_c;

	cur_c = *(sp->fmt);
	while (cur_c != '.' && not_in_list(cur_c, CONV_LIST) && *(sp->fmt)) // case: when there's no valid conv? @todo
	{
		(sp->fmt)++;
		cur_c = *(sp->fmt);
	}
}

// @todo same concerns as in prec function, get back here after correcting prec
// @todo meta function here for width and prec?
// could be func <- list of "endchars"

void		width_parser(t_format_specs *sp) 
{
	char	cur_c;

	sp->is_pad = TRUE;
	cur_c = *(sp->fmt);
	while (not_in_list(cur_c, CONV_LIST) && cur_c != '.') // not needed
	{
		if (cur_c == '*')
		{
			sp->pad = va_arg(*(sp->args), int);
			(sp->fmt)++;
			break ;
		}
		else if (is_in_list(cur_c, DIGITS))
		{
			sp->pad = ft_atoi(sp->fmt);
			offset(sp);
			break ;
		}
		else
			break ;
		(sp->fmt)++; // never executes?
		cur_c = *(sp->fmt);
	}
	cur_c = *(sp->fmt);
	if (cur_c == '.')	// also check if prec hasn't been set before that
		precision_parser(sp);
	else if (is_in_list(cur_c, CONV_LIST)) // do it elsewhere? seems unintuitive to be done here
		sp->conv = cur_c;
}


void		precision_parser(t_format_specs *sp)
{
	char	cur_c;

	sp->is_prec = TRUE;
	(sp->fmt)++;
	cur_c = *(sp->fmt);
	while (not_in_list(cur_c, CONV_LIST)) //probably not needed @todo delete
	{
		if (cur_c == '*')
		{
			sp->prec = va_arg(*(sp->args), int); // @todo what happens, if it's not an int there? if two ** in a row?
			(sp->fmt)++;
			break ; // check that next char is indeed a conversion, throw an error otherwise? @todo
		}
		else if (is_in_list(cur_c, DIGITS) || cur_c == '-') // is that the only allowed char here? @todo
		{
			sp->prec = ft_atoi(sp->fmt);
			offset(sp); //supposed to take us to conversion
			break ; // check that next char is indeed a conversion, throw an error otherwise? @todo
		}
		else
			break ;
		(sp->fmt)++; 		// this and next line never execute? or I'm missing smth @todo
		cur_c = *(sp->fmt); //
	}
}

void		format_spec_parser(t_format_specs *sp)
{
	(sp->fmt)++;
	reset_sp(sp);
	flag_parser(sp);
	if (*(sp->fmt) == '.')
		precision_parser(sp);
	else if (is_in_list(*(sp->fmt), DIGITS))
		width_parser(sp);
	else
		printf("parser error\n"); // @todo placeholder code

	if (is_in_list(*(sp->fmt), CONV_LIST)) // this is where conv is set, not in width!
	{
		sp->conv = *(sp->fmt);
		(sp->fmt)++;
	} // we don't need an else here, since conv is be default 'E', which is an error
}
