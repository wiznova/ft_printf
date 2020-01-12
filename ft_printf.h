/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:06:53 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/12 18:05:59 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_LIST "cspdiuxX%"
# define FLAG_LIST "-0" // * and . are part of width and precision respectively

# include <stdio.h> //delete before submission
# include <string.h> //delete before submission
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct	s_format_specs{
	int		justify; // 0 is default (right), 1 is left
	int		padding; // 0 by def, otherwise is parsed
	char	padding_ch; // ' ' by def, otherwise is 0
	int		precision; // 6 by def, otherwise parsed
}				t_format_specs;

int ft_printf(const char *, ...);

#endif