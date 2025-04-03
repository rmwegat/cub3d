/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:07:41 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/03 16:00:01 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <string.h>

# include "libft.h"

char	*get_next_line(int fd);

t_list	*find_last(t_list *lst);
void	lst_add_back(t_list **list, char *buf);
int		find_newline(t_list *list);
void	copy_str(t_list *list, char *next_str);
void	free_list(t_list **list, t_list *clean_node, char *buf);

#endif