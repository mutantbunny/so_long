/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:28:20 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/20 15:14:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	tmp = new_list;
	tmp->content = (int *)f(lst->content);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp = tmp->next;
		if (tmp == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		tmp->content = (int *)f(lst->content);
		lst = lst->next;
	}
	tmp->next = NULL;
	return (new_list);
}
