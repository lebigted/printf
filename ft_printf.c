/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:44:10 by ltestard          #+#    #+#             */
/*   Updated: 2022/12/05 10:45:50 by ltestard         ###   ########.fr       */
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
			result += convert_functions(p_arg, parms[i + 1]);
			i++;
		}
		else
			result += putchar(parms[i]);
			i++;
	}
	va_end(p_arg);
	return (result);
}

int convert_fonctions(va_list p_arg,char forma)
{
	int i;

	i = 0;
	if (forma == 'c')
		i += my_putsr(va_arg(p_arg, int));
	else if (forma == 's')
		i += my_putsr(va_arg(p_arg, char *));
	else if (forma == 'p')
		i += my_nbrbase(va_arg(p_arg, unsigned long));
	else if (forma == 'd' || forma == 'i')
		i += my_putnbr(va_arg(p_arg, int));
	else if (forma == 'u')
		i += my_putnbr(va_arg(p_arg, unsigned int));
	else if (forma == 'x')
		i += my_nbrbase(va_arg(p_arg, unsigned int));
	else if (forma == 'X')
		i += my_nbrbase(va_arg(p_arg, unsigned int));
	else if (forma == '%')
		i += my_putchar(i);
	return (i);
}

