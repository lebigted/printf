/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:44:10 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/18 19:42:24 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *parms, ...)
{
	va_list p_arg;
	int i;
	int result[1];

	va_start(p_arg, parms);
	i = 0;
	*result = 0;
	while (parms[i])
	{
		if(parms[i] == '%')
		{
			convert_fonctions(p_arg, parms[i + 1], result);
			i++;
		}
		else
			forma_my_char(parms[i], result);
		i++;
	}
	va_end(p_arg);
	return (*result);
}

void	convert_fonctions(va_list p_arg,char forma, int *res)
{
	if (forma == 'c')
		forma_my_char(va_arg(p_arg, int), res);
	else if (forma == 's')
		forma_my_putstr(va_arg(p_arg, char *),res);
	else if (forma == 'p')
		forma_my_nbrbase(va_arg(p_arg, int), "0123456789abcdef",res);
	else if (forma == 'd' || forma == 'i')
		forma_my_nbr(va_arg(p_arg, int), res);
	else if (forma == 'u')
		forma_my_nbr(va_arg(p_arg, unsigned int), res);
	else if (forma == 'x')
		ft_argputnbr_base(va_arg(p_arg, unsigned long), 0, res);
	else if (forma == 'X')
		ft_argputnbr_base(va_arg(p_arg, unsigned long), 1, res);
	else if (forma == '%')
		forma_my_char('%', res);
}


// #include <stdio.h>
// int main(void)
// {
//   // Test avec un spécificateur de conversion 'c'
//   ft_printf("Caractère: %c\n", 'A');

//   // Test avec un spécificateur de conversion 's'
//   ft_printf("Chaîne de caractères: %s\n", "Bonjour");

//   // Test avec un spécificateur de conversion 'p'
//   int *ptr = NULL;
//   ft_printf("Pointeur: %p\n", ptr);

//   // Test avec un spécificateur de conversion 'd'
//   ft_printf("Entier: %d\n", 123);

//   // Test avec un spécificateur de conversion 'i'
//   ft_printf("Entier: %i\n", -456);

//   // Test avec un spécificateur de conversion 'u'
//   ft_printf("Entier non signé: %u\n", 789);

//   // Test avec un spécificateur de conversion 'x'
//   ft_printf("Entier non signé en hexadécimal (minuscule): %x\n", 123456);

//   // Test avec un spécificateur de conversion 'X'
//   ft_printf("Entier non signé en hexadécimal (majuscule): %X\n", 654321);

//   // Test avec un spécificateur de conversion '%'
//   ft_printf("Pourcentage: %%\n");

//   return 0;
// }
