/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:52:03 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/09 17:52:30 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция производит очистку всего листа*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*entry;

	entry = *lst;
	while (entry)
	{
		tmp = entry->next;
		if (del)
			del(entry->content);
		free(entry);
		entry = tmp;
	}
	*lst = NULL;
}
