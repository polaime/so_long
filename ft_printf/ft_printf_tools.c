/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:36:55 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/05 13:56:16 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putunbr(unsigned int nb)
// {
// 	static int		i;
// 	char			nbc;

// 	if (nb >= 10)
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// 	else
// 	{
// 		nbc = nb + '0';
// 		i++;
// 		write(1, &nbc, 1);
// 	}
// 	return (i);
// }

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_printx(void)
{
	return (write(1, "%", 1));
}
