/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:22:07 by lviguier          #+#    #+#             */
/*   Updated: 2024/06/19 16:33:08 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptrlen(unsigned long long nbr)
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

int	ft_printhexptr(unsigned long long nbr)
{
	int	printed_nbrs;

	printed_nbrs = 0;
	if (nbr > 16)
	{
		ft_printhexptr(nbr / 16);
		ft_printhexptr(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			printed_nbrs += ft_printchar(nbr + '0');
		else
			printed_nbrs += ft_printchar(nbr + 'a' - 10);
	}
	return (printed_nbrs);
}

int	ft_printptr(unsigned long long nbr)
{
	int	printed_nbrs;

	printed_nbrs = 0;
	printed_nbrs += ft_printstr("0x");
	if (nbr == 0)
		printed_nbrs += ft_printchar('0');
	else
	{
		printed_nbrs += ft_ptrlen(nbr);
		ft_printhexptr(nbr);
	}
	return (printed_nbrs);
}
