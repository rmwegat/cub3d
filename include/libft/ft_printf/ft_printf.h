/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:56:17 by rwegat            #+#    #+#             */
/*   Updated: 2024/03/22 20:38:50 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
void	ft_printptr(void *p, int *len);
void	ft_printunsigned(unsigned int n, int *len);
void	ft_printhex(unsigned int nbr, int *len, const char s);
void	ft_printchar(int c, int *len);
void	ft_printint(int n, int *len);
void	ft_printstr(char *s, int *len);

#endif
