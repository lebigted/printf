/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_my_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:17:35 by ltestard          #+#    #+#             */
/*   Updated: 2022/12/06 23:45:47 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	forma_my_nbr(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
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
