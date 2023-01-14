/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:10:44 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/14 03:52:22 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_argputnbr_base(unsigned long n, int d);
int forma_my_nbrbase_ten( int nb);
int	forma_my_putstr(char *str);
int	forma_my_nbr( int nb);
int	forma_my_char(int c);
int	forma_my_printf(const char *parms, ...);
int	convert_fonctions(va_list p_arg,char forma);

#endif
