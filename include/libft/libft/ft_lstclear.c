/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:02:54 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/03 15:18:24 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
