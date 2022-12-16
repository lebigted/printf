/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:19:25 by ltestard          #+#    #+#             */
/*   Updated: 2022/12/16 05:04:41 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "printf.h"

int	forma_fonctions(va_list p_arg,char forma)
{
	int i;

	i = 0;
	if (forma == 'c')
		i += forma_my_char(va_arg(p_arg, int));

	else if (forma == 's')
		i += forma_my_putstr(va_arg(p_arg, char *));

	else if (forma == 'p')
		i += forma_my_nbrbase(va_arg(p_arg, void *));

	else if (forma == 'd' || forma == 'i')
		i += forma_my_nbr(va_arg(p_arg, int));

	else if (forma == 'u')
		i += forma_my_nbr(va_arg(p_arg, unsigned long));

	else if (forma == 'x')
		i += forma_my_nbrbase(va_arg(p_arg, unsigned int));

	else if (forma == 'X')
		i += forma_my_nbrbase(va_arg(p_arg, unsigned int));

	else if (forma == '%')
		i += forma_my_char(i);
	return (i);
}
/*
