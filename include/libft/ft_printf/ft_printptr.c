/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:56:53 by rwegat            #+#    #+#             */
/*   Updated: 2024/03/22 20:39:58 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printptr_hex(unsigned long long nbr, int *len)
{
	if (nbr >= 16)
	{
		ft_printptr_hex(nbr / 16, len);
		if ((*len) != -1)
			ft_printchar("0123456789abcdef"[nbr % 16], len);
	}
	else
		if ((*len) != -1)
			ft_printchar("0123456789abcdef"[nbr % 16], len);
}

void	ft_printptr(void *p, int *len)
{
	unsigned long long	n;	

	n = (unsigned long long)p;
	ft_printstr("0x", len);
	if ((*len) != -1)
		ft_printptr_hex(n, len);
}
