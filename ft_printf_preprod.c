/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_preprod.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 18:07:04 by skhalil        #+#    #+#                */
/*   Updated: 2020/01/22 19:18:21 by skhalil       ########   odam.nl         */
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

void	init_spec_defaults(t_format_specs *specs, va_list *args)
{
	specs->justify = 0;
	specs->padding = 0;
	specs->padding_ch = ' ';
	specs->precision = 0;
	specs->args = args;
	specs->ret = 0;
}

int		ft_putchar_fd_ret(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_numlen(int n)
{
	char *num_str;

	num_str = ft_itoa(n);
	n = ft_strlen(num_str);
	free(num_str);
	return (n);
}

void	ft_putnbr_fd_co(int n, int fd, int *co)
{
	if (n == -2147483648)
	{
		*co += ft_putchar_fd_ret('-', fd);
		*co += ft_putchar_fd_ret('2', fd);
		ft_putnbr_fd_co(147483648, fd, co);
	}
	else if (n < 0)
	{
		*co += ft_putchar_fd_ret('-', fd);
		ft_putnbr_fd_co(-n, fd, co);
	}
	else if (n > 9)
	{
		ft_putnbr_fd_co(n / 10, fd, co);
		ft_putnbr_fd_co(n % 10, fd, co);
	}
	else
	{
		*co += ft_putchar_fd_ret(n + '0', fd);
	}
}

void	launch_conversion(char conv, t_format_specs *temp_specs, va_list *args)
{
	int		d;
	int		start;

	start = 0;
	if (conv == 'd')
	{
		d = va_arg(*args, int); 
		if (ft_numlen(d) >= temp_specs->padding)
			ft_putnbr_fd_co(d, 1, &(temp_specs->ret));
		// else if (temp_specs->precision)
		else
		{
			start = temp_specs->ret;
			while (temp_specs->ret - start != temp_specs->padding - ft_numlen(d))
				temp_specs->ret += ft_putchar_fd_ret(temp_specs->padding_ch, 1);
			ft_putnbr_fd_co(d, 1, &(temp_specs->ret));			
		}
		
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
	init_spec_defaults(&specs, &args);
	while (*format)
	{
		if (*format == '%')
		{
			temp_specs = format_spec_parser(&format, specs);
			while (is_in_list(*format, "-0")) //patch for neg precision or 0 in prec
				format++;
			if (is_in_list(*format, CONV_LIST) != 0)
				launch_conversion(*format, &temp_specs, &args);
			ret += temp_specs.ret;
		}
		else
		{
			write(1, format, 1);
			ret++;
		}
		format++;
		// first_arg = va_arg(args, int);
	}
	va_end(args);
	return (ret);
}
