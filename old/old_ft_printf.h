/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:06:53 by skhalil        #+#    #+#                */
/*   Updated: 2020/03/12 17:40:15 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DIGITS "1234567890"
# define CONV_LIST "cspdiuxX%"
# define FLAG_LIST "-0" // * and . are part of width and precision respectively
# define TRUE 1
# define FALSE 0
# define LEFT 1
# define RIGHT 0

// delete ft_printf_preprod.c file before submission

# include <stdio.h> //delete before submission
# include <string.h> //delete before submission
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

typedef struct	s_nextarg{
	char	c;
}				t_nextarg;

typedef struct	s_format_specs{
	int			just;    // 0 is default (right), 1 is left
	int			is_pad;  // boolean, 1 if padding was specified
	int			pad;     // parsed value, 0 by def
	char		pad_ch;  // ' ' by def, otherwise is 0
	int			is_prec; // boolean, 1 if precision was specified
	int			prec;    // 6 by def for floats, otherwise parsed
	char		conv;    // conversion char, by def: 'E' ('error' - means conversion not known)
	t_nextarg	na;      // stands for "next argument"
	va_list		*args;
	char		*fmt;
	int			ret;
}				t_format_specs;


int		ft_printf(const char *format, ...);
char	is_in_list(char c, char *list);
char	not_in_list(char c, char *list);
void	flag_parser(t_format_specs *sp);
void	precision_parser(t_format_specs *sp);
void	initialize_sp(t_format_specs *sp, va_list *args, char *format);
void	reset_sp(t_format_specs *sp);
void	format_spec_parser(t_format_specs *sp);
void	write_one(char ch, t_format_specs *sp);
void	ft_putnbr_co(int n, t_format_specs *sp);
int		ft_numlen(int n);


#endif