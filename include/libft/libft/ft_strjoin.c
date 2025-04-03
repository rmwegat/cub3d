/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:26:43 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/18 11:49:43 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		y;

	y = 0;
	i = 0;
	joined = (char *)malloc((sizeof(*s1) * (ft_strlen(s1))) \
	+ (sizeof(*s2) * (ft_strlen(s2))) + 1);
	if (!joined)
		return (NULL);
	while (s1[y])
	{
		joined[i] = s1[y];
		i++;
		y++;
	}
	y = 0;
	while (s2[y])
	{
		joined[i] = s2[y];
		i++;
		y++;
	}
	joined[i] = '\0';
	return (joined);
}
