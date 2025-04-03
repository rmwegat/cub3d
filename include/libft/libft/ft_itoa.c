/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:12:12 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/30 13:44:06 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*reversestr(char *str)
{
	char	temp;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*do_itoa(int n, char *converted)
{
	int	polarity;
	int	i;

	i = 0;
	polarity = 1;
	if (n < 0)
	{
		polarity = -1;
		n = -n;
	}
	while (n > 0)
	{
		converted[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (polarity < 0)
	{
		converted[i] = '-';
		i++;
	}
	converted[i] = '\0';
	return (reversestr(converted));
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = numlen(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result = do_itoa(n, result);
	return (result);
}
