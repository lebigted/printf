/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:44:10 by ltestard          #+#    #+#             */
/*   Updated: 2022/12/29 18:00:04 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int my_printchar(int c)
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
/*
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
}*/

int count_convert_fonctions(char forma, va_list p_arg)
{
    int count = 0;

    if (forma == 'c')
        count++;
    else if (forma == 's')
        count += forma_my_putstr_len(va_arg(p_arg, char *));
    else if (forma == 'p')
        count += forma_my_nbrbase_len(va_arg(p_arg, unsigned long));
    else if (forma == 'd' || forma == 'i')
        count += count_forma_my_nbr(va_arg(p_arg, int));
    else if (forma == 'u')
        count += count_forma_my_nbr(va_arg(p_arg, unsigned int));
    else if (forma == 'x')
        count += count_forma_my_nbrbase(va_arg(p_arg, unsigned int));
    else if (forma == 'X')
        count += count_forma_my_nbrbase(va_arg(p_arg, unsigned int));
    else if (forma == '%')
        count++;

    return count;
}

int main(void) 
{
  // Test avec un spécificateur de conversion 'c'
  ft_printf("Caractère: %c\n", 'A');

  // Test avec un spécificateur de conversion 's'
  ft_printf("Chaîne de caractères: %s\n", "Bonjour");

  // Test avec un spécificateur de conversion 'p'
  int *ptr = NULL;
  ft_printf("Pointeur: %p\n", ptr);

  // Test avec un spécificateur de conversion 'd'
  ft_printf("Entier: %d\n", 123);

  // Test avec un spécificateur de conversion 'i'
  ft_printf("Entier: %i\n", -456);

  // Test avec un spécificateur de conversion 'u'
  ft_printf("Entier non signé: %u\n", 789);

  // Test avec un spécificateur de conversion 'x'
  ft_printf("Entier non signé en hexadécimal (minuscule): %x\n", 123456);

  // Test avec un spécificateur de conversion 'X'
  ft_printf("Entier non signé en hexadécimal (majuscule): %X\n", 654321);

  // Test avec un spécificateur de conversion '%'
  ft_printf("Pourcentage: %%\n");

  return 0;
}

