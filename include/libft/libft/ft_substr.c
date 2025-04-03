/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:28:10 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/31 13:03:07 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			y;

	y = 0;
	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if ((y < len) && (i >= start))
		{
			substr[y] = s[i];
			y++;
		}
		i++;
	}
	substr[y] = '\0';
	return (substr);
}
