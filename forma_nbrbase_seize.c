# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    forma_nbrbase_seize                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 03:32:05 by ltestard          #+#    #+#              #
#    Updated: 2023/01/14 03:32:09 by ltestard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

int	ft_argputnbr_base(unsigned long n, int d)
{
	char			*base;
	char			c;
	int				j;
	unsigned int	k;

	j = 0;
	if (d == 0)
		base = "0123456789abcdef";
	if (d == 1)
		base = "0123456789ABCDEF";
	if (d == 2)
		base = "0123456789";
	k = ft_strlen(base);
	if (n >= k)
	{
		j += ft_argputnbr_base((n / k), d);
		j += ft_argputnbr_base((n % k), d);
	}
	if (n < k)
	{
		c = base[n];
		j += ft_argputchar(c);
	}
	return (j);
}
