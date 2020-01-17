/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:06:53 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/17 19:37:39 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_LIST "cspdiuxX%"
# define FLAG_LIST "-0" // * and . are part of width and precision respectively

// delete ft_printf_preprod.c file before submission

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

int				ft_printf(const char *format, ...);
char			is_in_list(char c, char *list);
void			flag_parser(const char **format, t_format_specs *specs);
void			precision_parser(const char **format, t_format_specs *specs, va_list *args);
t_format_specs	format_spec_parser(const char **format, t_format_specs specs, va_list *args);

#endif