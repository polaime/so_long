/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:46:48 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/05 13:56:00 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	checkbar_nbr(const char str, va_list ap)
{
	int		j;

	j = 0;
	if (str == 'i' || str == 'd')
		j = ft_putnbr(va_arg(ap, int));
	if (str == 'x')
		j = ft_putx(va_arg(ap, unsigned int));
	if (str == 'u')
		j = ft_putnbr(va_arg(ap, unsigned int));
	if (str == 'X')
		j = ft_putx2(va_arg (ap, unsigned int));
	return (j);
}

int	checkbar(const char str, va_list ap)
{
	int					j;
	unsigned long long	k;

	j = 0;
	if (str == 0)
		return (0);
	if (str == 'c')
		j = ft_putchar((char)va_arg(ap, int));
	if (str == 's')
		j = ft_putustr(va_arg(ap, char *), 0);
	if (str == 'p')
	{
		k = va_arg(ap, unsigned long long);
		if (k)
			j = write(1, "0x", 2);
		j += ft_putptr(k);
	}
	if (str == '%')
		j = ft_printx();
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	ap;

	j = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			j = j + checkbar(str[i + 1], ap);
			j = j + checkbar_nbr(str[i + 1], ap);
			i++;
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (j);
}
