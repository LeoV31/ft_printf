/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:22:07 by lviguier          #+#    #+#             */
/*   Updated: 2024/06/19 16:32:32 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_hexlen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_printhex(unsigned int nbr, char format)
{
	int	printed_nbrs;

	printed_nbrs = 0;
	if (nbr >= 16)
	{
		ft_printhex(nbr / 16, format);
		ft_printhex(nbr % 16, format);
	}
	else
	{
		if (nbr < 10)
			printed_nbrs += ft_printchar(nbr + '0');
		else if (format == 'x')
			printed_nbrs += ft_printchar(nbr + 'a' - 10);
		else if (format == 'X')
			printed_nbrs += ft_printchar(nbr + 'A' - 10);
	}
	return (printed_nbrs);
}

int	ft_printnbrhex(unsigned int nbr, char format)
{
	int	printed_nbrs;

	printed_nbrs = 0;
	if (nbr == 0)
		printed_nbrs += ft_printchar('0');
	else
	{
		printed_nbrs += ft_hexlen(nbr);
		ft_printhex(nbr, format);
	}
	return (printed_nbrs);
}
