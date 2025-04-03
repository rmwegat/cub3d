/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:20:12 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/30 12:11:33 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = ft_strdup(s);
	if (!result)
		return (NULL);
	while (result[i])
	{
		result[i] = (*f)(i, result[i]);
		i++;
	}
	return (result);
}
