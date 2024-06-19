/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:51:15 by lviguier          #+#    #+#             */
/*   Updated: 2024/06/19 16:30:50 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_ptrlen(unsigned long long nbr);
int		ft_printhexptr(unsigned long long nbr);
int		ft_printptr(unsigned long long nbr);
int		ft_printnbr(int nbr);
int		ft_unsnbrlen(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_printunsigned(unsigned int nbr);
int		ft_hexlen(unsigned int nbr);
int		ft_printhex(unsigned int nbr, char format);
int		ft_printnbrhex(unsigned int nbr, char format);
int		ft_print(va_list args, const char format);
int		ft_printf(const char *format, ...);

#endif
