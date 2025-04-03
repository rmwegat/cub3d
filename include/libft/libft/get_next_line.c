/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:21:19 by rwegat            #+#    #+#             */
/*   Updated: 2023/12/11 17:04:17 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buf;

	while (!find_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buf);
			return ;
		}
		buf[chars_read] = '\0';
		lst_add_back(list, buf);
	}
}

int	get_line_len(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list -> str_buf[i])
		{
			if (list -> str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

char	*get_one_line(t_list *list)
{
	char	*next_str;
	int		str_len;

	if (!list)
		return (NULL);
	str_len = get_line_len(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	free_upto_newline(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		old_str;
	int		new_str;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last(*list);
	old_str = 0;
	new_str = 0;
	while (last_node->str_buf[old_str] && last_node->str_buf[old_str] != '\n')
		old_str++;
	while (last_node->str_buf[old_str] && last_node->str_buf[old_str++])
		buf[new_str++] = last_node->str_buf[old_str];
	buf[new_str] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	free_list(list, clean_node, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &next_line, 0) < 0)
	{
		free_list(&list, NULL, NULL);
		return (NULL);
	}
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_one_line(list);
	if (!next_line && list)
		free_list(&list, NULL, NULL);
	else
		free_upto_newline(&list);
	return (next_line);
}
