/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_my_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:17:35 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/10 20:18:30 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int countkjdfskjfqklfjlaqfjdlq
f,qs
qdqsd
qsdqsd
qsd


putchar

int	forma_my_nbr(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return nb;
	}
	else if (nb < 0)
	{
		nb = -1 * nb;
		forma_my_char('-');
	}
	if (nb > 9)
	{
		forma_my_nbr(nb / 10);
		forma_my_nbr(nb % 10);
	}
	else
	{
		forma_my_char(nb + '0');
	}
	return (1);
}

int forma_my_nbrbase(unsigned int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	nb = (unsigned int)nb;
	if (nb / 16)
		ft_putnbr(nb / 16);
	ft_putchar((nb % 16) + '0');
}

