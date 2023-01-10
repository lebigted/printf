/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_my_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:17:35 by ltestard          #+#    #+#             */
/*   Updated: 2022/12/22 15:41:25 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int count_forma_my_nbr(unsigned int nb)
{
    if (nb == 0)
        return 1;
    else if (nb < 0)
        return count_forma_my_nbr(-1 * nb) + 1;
    else
        return count_forma_my_nbr(nb / 10) + 1;
}

int count_forma_my_nbrbase(unsigned int nb)
{
    if (nb < 0)
        return count_forma_my_nbrbase(-1 * nb) + 1;
    else if (nb < 16)
        return 1;
    else
        return count_forma_my_nbrbase(nb / 16) + 1;
}

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
		forma_my_char('-');
		nb *= -1;
	}
	nb = (unsigned int)nb;
	if (nb / 16)
		forma_my_nbrbase(nb / 16);
	forma_my_char((nb % 16) + '0');
}