/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:57:09 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/31 11:09:18 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	getend(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (ft_strchr(set, s1[i - 1]) == NULL)
			break ;
		i--;
	}
	return (i);
}

size_t	getstart(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}
