/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_my_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:12:09 by ltestard          #+#    #+#             */
/*   Updated: 2023/01/20 17:04:46 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	forma_my_putstr(char *str, int *res)
{
	int	i;

	i = 0;
	if (!str)
	{
		forma_my_putstr("(null)", res);
		return ;
	}
	while (str[i])
	{
		forma_my_char(str[i], res);
		i++;
	}
}

void	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
}
