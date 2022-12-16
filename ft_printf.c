/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:44:10 by ltestard          #+#    #+#             */
/*   Updated: 2022/12/16 04:49:27 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int my_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_printf(const char *parms, ...)
{
	va_list p_arg;
	int i;
	int result;

	va_start(p_arg, parms);
	i = 0;
	result = 0;
	while (parms[i])
	{
		if(parms[i] == '%')
		{
			result += convert_fonctions(p_arg, parms[i + 1]);
			i++;
		}
		else
			result += my_printchar(parms[i]);
			i++;
	}
	va_end(p_arg);
	return (result);
}

int	convert_fonctions(va_list p_arg,char forma)
{
	int i;

	i = 0;
	if (forma == 'c')
		i += forma_my_char(va_arg(p_arg, int));
	else if (forma == 's')
		i += forma_my_putstr(va_arg(p_arg, char *));
	else if (forma == 'p')
		i += forma_my_nbrbase(va_arg(p_arg, unsigned long));
	else if (forma == 'd' || forma == 'i')
		i += forma_my_nbr(va_arg(p_arg, int));
	else if (forma == 'u')
		i += forma_my_nbr(va_arg(p_arg, unsigned int));
	else if (forma == 'x')
		i += forma_my_nbrbase(va_arg(p_arg, unsigned int));
	else if (forma == 'X')
		i += forma_my_nbrbase(va_arg(p_arg, unsigned int));
	else if (forma == '%')
		i += forma_my_char(i);
	return (i);
}

