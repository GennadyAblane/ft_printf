/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:34:32 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*con;

	con = (void *)malloc(sizeof(void) * content_size);
	if (!con)
		return (0);
	tmp = malloc(sizeof(t_list));
	if (!tmp)
	{
		free(con);
		return (0);
	}
	if (!content)
	{
		tmp->content = 0;
		tmp->content_size = 0;
		tmp->next = 0;
		return (tmp);
	}
	con = ft_memcpy(con, content, content_size);
	tmp->content = con;
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
