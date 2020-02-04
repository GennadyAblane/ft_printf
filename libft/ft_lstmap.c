/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:14:12 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*end;
	t_list	*n;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	end = ft_lstnew(new->content, new->content_size);
	if (!end)
		return (NULL);
	lst = lst->next;
	n = end;
	while (lst)
	{
		new = f(lst);
		end->next = ft_lstnew(new->content, new->content_size);
		if (!end->next)
		{
			ft_lstdel(&n, ft_del);
			return (NULL);
		}
		end = end->next;
		lst = lst->next;
	}
	return (n);
}
