/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:57:05 by rwegat            #+#    #+#             */
/*   Updated: 2024/03/22 20:39:58 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *s, int *len)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			(*len) = -1;
		else
			(*len) += 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_printchar(s[i], len);
			i++;
			if ((*len) == -1)
				break ;
		}
	}
}
// int main(void)
// {
// 	char s[] = "blablabla";
// 	ft_printstr_fd(s, 1);
// }
