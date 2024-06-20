/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:22:07 by lviguier          #+#    #+#             */
/*   Updated: 2024/06/19 16:32:59 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	if (str == 0)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printnbr(int nbr)
{
	int		len;
	char	*str;

	ft_putnbr_fd(nbr, 1);
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_print(va_list *args, const char format)
{
	int	printed_chars;

	printed_chars = 0;
	if (format == 'c')
		printed_chars += ft_printchar(va_arg(*args, int));
	else if (format == 's')
		printed_chars += ft_printstr(va_arg(*args, char *));
	else if (format == 'p')
		printed_chars += ft_printptr(va_arg(*args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printed_chars += ft_printnbr(va_arg(*args, int));
	else if (format == 'u')
		printed_chars += ft_printunsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed_chars += ft_printnbrhex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		printed_chars += ft_printchar('%');
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;
	int		i;

	printed_chars = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed_chars += ft_print(&args, format[i + 1]);
			i++;
		}
		else
			printed_chars += ft_printchar((int)format[i]);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
/**
#include <stdio.h>

int	main(void)
{
	int	lenft;
	int	lenprintf;
	char	c = 'c';
	char	*s = "hello";
	int	nbr = 123;
	unsigned int nbrun = 1234;

	lenft = ft_printf("single character: %c\nstring: %s\npointer: %p\ndecimal: \
	%d\ninteger: %i\nunsinged decimal: %u\nhex lowcase: \
	%x\nhex upcase: %X\npercent: %%\n", \
	c, s, s, nbr, nbr, nbrun, nbr, nbr);
	lenprintf = printf("single character: %c\nstring: %s\npointer: %p\ndecimal: \
	%d\ninteger: %i\nunsinged decimal: %u\nhex lowcase: \
	%x\nhex upcase: %X\npercent: %%\n", \
	c, s, s, nbr, nbr, nbrun, nbr, nbr);
	printf("my funcion result len: %i\n the official printf len: %i\n"\
	, lenft, lenprintf);
}
**/
