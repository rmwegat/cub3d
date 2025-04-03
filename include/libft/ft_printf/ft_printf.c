/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:56:10 by rwegat            #+#    #+#             */
/*   Updated: 2024/03/22 20:39:20 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_format(const char s, va_list args, int *len)
{
	if (s == 'c')
		ft_printchar(va_arg(args, int), len);
	else if (s == 's')
		ft_printstr(va_arg(args, char *), len);
	else if (s == 'p')
		ft_printptr(va_arg(args, void *), len);
	else if (s == 'd' || s == 'i')
		ft_printint(va_arg(args, int), len);
	else if (s == 'u')
		ft_printunsigned(va_arg(args, unsigned int), len);
	else if (s == 'x' || s == 'X')
		ft_printhex(va_arg(args, unsigned int), len, s);
	else if (s == '%')
		ft_printchar('%', len);
}

int	ft_printf(const char *string, ...)
{
	va_list			args;
	int				i;
	int				len;

	len = 0;
	va_start(args, string);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			check_format(string[i + 1], args, &len);
			i++;
		}
		else
			ft_printchar(string[i], &len);
		i++;
		if (len == -1)
			break ;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int i = 0;
// 	printf("real printf:");
// 	i = printf("\n");
// 	printf("%i\n, i");
// 	printf("my printf:");
// 	i = ft_printf("\n");
// 	printf("%i\n, i");
// }
