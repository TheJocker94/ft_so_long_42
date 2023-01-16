/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:56:56 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/12 17:56:58 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*new;

	lst2 = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
			ft_lstclear(&lst2, del);
		ft_lstadd_back(&lst2, new);
		lst = lst->next;
	}
	return (lst2);
}
