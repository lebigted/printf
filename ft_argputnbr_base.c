/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argputnbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:18:53 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/18 19:59:27 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_argputnbr_base(unsigned long n, int d, int *res)
{
	char			*base;
	char			c;
	int				j;
	unsigned long	k;

	if (d == 0)
		base = "0123456789abcdef";
	if (d == 1)
		base = "0123456789ABCDEF";
	k = (ft_strlen((unsigned long)base));
	if (n >= k)
	{
		forma_my_nbrbase((n / k), base, res);
		forma_my_nbrbase((n % k), base, res);
	}
	if (n < k)
	{
		c = base[n];
		forma_my_char(c, res);
	}
}
