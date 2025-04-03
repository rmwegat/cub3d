/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:37:45 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/24 13:22:28 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	y;
	size_t	src_len;

	i = 0;
	y = ft_strlen(dst);
	dst_len = y;
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		dst_len = dstsize;
	if (dst_len < dstsize)
	{
		while (src[i] && y < dstsize - 1)
		{
			dst[y] = src[i];
			i++;
			y++;
		}
		dst[y] = '\0';
	}
	return (dst_len + src_len);
}
