/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:54:20 by rwegat            #+#    #+#             */
/*   Updated: 2023/10/23 19:24:52 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	toconvert;
	int	polarity;

	i = 0;
	toconvert = 0;
	polarity = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+')
		polarity = 1;
	if (str[i] == '-')
		polarity = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		toconvert = (toconvert * 10) + (str[i] - '0');
		i++;
	}
	return (toconvert * polarity);
}
