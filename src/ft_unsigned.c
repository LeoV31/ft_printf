/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:22:07 by lviguier          #+#    #+#             */
/*   Updated: 2024/06/19 16:33:21 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_unsnbrlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int			len;
	long long	m;
	char		*result;

	len = ft_unsnbrlen(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	m = n;
	if (m == 0)
		result[0] = '0';
	if (m < 0)
	{
		result[0] = '-';
		m *= -1;
	}
	while (len-- > 0 && m > 0)
	{
		result[len] = (m % 10) + '0';
		m /= 10;
	}
	return (result);
}

int	ft_printunsigned(unsigned int nbr)
{
	char	*str;

	str = ft_uitoa(nbr);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
