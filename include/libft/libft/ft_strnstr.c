/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:01:39 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/02 19:02:22 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		y = 0;
		while (haystack[i + y] == needle[y] && (i + y) < len)
		{
			y++;
			if (!needle[y])
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
