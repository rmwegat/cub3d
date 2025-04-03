/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:12:10 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/11 14:26:50 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (i < len)
	{
		*(unsigned char *)(b + i) = uc;
		i++;
	}
	return (b);
}
