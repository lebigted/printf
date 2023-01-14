/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_my_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:17:35 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/14 03:36:07 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	forma_my_nbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return nb;
	}
	else if (nb < 0)
	{
		nb *= - 1;
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

int forma_my_nbrbase(int nb)
{
	if (nb < 0)
	{
		forma_my_char('-');
		nb *= -1;
	}
	nb = (unsigned int)nb;
	if (nb / 16)
		forma_my_nbrbase(nb / 16);
	forma_my_char((nb % 16) + '0');
	return(0);
}

int forma_my_nbrbase_ten(int nb)
{
	if (nb < 0)
	{
		forma_my_char('-');
		nb *= -1;
	}
	nb = (unsigned int)nb;
	if (nb / 10)
		forma_my_nbrbase(nb / 10);
	forma_my_char((nb % 10) + '0');
	return(0);
}

