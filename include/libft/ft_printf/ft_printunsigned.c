/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:57:11 by rwegat            #+#    #+#             */
/*   Updated: 2024/03/22 20:39:58 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunsigned(unsigned int n, int *len)
{
	if (n >= 10)
	{
		ft_printunsigned(n / 10, len);
		if ((*len) != -1)
			ft_printchar((n % 10) + '0', len);
	}
	else
		if ((*len) != -1)
			ft_printchar((n % 10) + '0', len);
}
