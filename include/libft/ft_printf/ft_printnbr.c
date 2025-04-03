/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:56:44 by rwegat            #+#    #+#             */
/*   Updated: 2024/03/22 20:39:58 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printint(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_printstr("-2", len);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_printchar('-', len);
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_printint(n / 10, len);
		if ((*len) != -1)
			ft_printchar((n % 10) + '0', len);
	}
	else
		if ((*len) != -1)
			ft_printchar((n % 10) + '0', len);
}
