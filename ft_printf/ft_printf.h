/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:17:44 by pthibaud          #+#    #+#             */
/*   Updated: 2025/05/05 13:56:34 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define HEXA_MIN "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"

int		ft_putnbr(long int nb);
int		ft_putptr(unsigned long long nb);
int		ft_putustr(char *s, int i);
int		ft_putx2(unsigned int nb);
int		ft_putx(unsigned int nb);
int		ft_printf(const char *str, ...);
int		ft_putunbr(unsigned int nb);
int		ft_putchar(char c);
int		ft_printx(void);
#endif