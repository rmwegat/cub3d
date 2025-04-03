/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:56:33 by rwegat            #+#    #+#             */
/*   Updated: 2024/03/22 20:39:58 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned int nbr, int *len, const char s)
{
	if (nbr < 0)
	{
		ft_printchar('-', len);
		nbr = nbr * (-1);
	}
	if (nbr >= 16)
	{
		ft_printhex(nbr / 16, len, s);
		if ((*len) != -1)
		{
			if (s == 'x')
				ft_printchar("0123456789abcdef"[nbr % 16], len);
			if (s == 'X')
				ft_printchar("0123456789ABCDEF"[nbr % 16], len);
		}
		return ;
	}
	if ((*len) != -1)
	{
		if (s == 'x')
			ft_printchar("0123456789abcdef"[nbr % 16], len);
		if (s == 'X')
			ft_printchar("0123456789ABCDEF"[nbr % 16], len);
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	int len;

// 	len = 0;
// 	ft_printhex(25345345, &len, 'X');
// }