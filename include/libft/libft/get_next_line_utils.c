/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:23:48 by rwegat            #+#    #+#             */
/*   Updated: 2023/12/11 17:06:04 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	if (list -> next == NULL)
		return (list);
	return (find_last(list -> next));
}

void	lst_add_back(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node -> next = new_node;
	new_node -> str_buf = buf;
	new_node -> next = NULL;
}

int	find_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	copy_str(t_list *list, char *str)
{
	int	list_counter;
	int	str_counter;

	str_counter = 0;
	if (!list)
		return ;
	while (list)
	{
		list_counter = 0;
		while (list->str_buf[list_counter])
		{
			if (list->str_buf[list_counter] == '\n')
			{
				str[str_counter++] = '\n';
				str[str_counter] = '\0';
				return ;
			}
			str[str_counter++] = list->str_buf[list_counter++];
		}
		list = list->next;
	}
	str[str_counter] = '\0';
}

void	free_list(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*current;
	t_list	*next;

	if (*list == NULL)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		free(current->str_buf);
		free(current);
		current = next;
	}
	*list = NULL;
	if (!clean_node || !buf)
		return ;
	if (clean_node->str_buf[0] && clean_node)
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
