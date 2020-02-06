/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:21:51 by ablane            #+#    #+#             */
/*   Updated: 2020/02/06 10:59:24 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_strspace(size_t size, size_t z)
{
	char	*str;
	size_t	i;


	i = 0;
	if (size == (size_t)(-1))
		return (0);
	str = (char*)malloc(size + 1);
	if (!str)
		return (0);
	if (z == 2)
	{
		while (i < size)
			str[i++] = 48;
		str[i] = '\0';
	}
	else
	{
		while (i < size)
			str[i++] = 32;
		str[i] = '\0';
	}
	return (str);
}

int count(t_str *tmp, size_t n)
{
	while (tmp->next)
		tmp = tmp->next;
	if (n > tmp->counchar)
		return (1);
	return (0);
}

void ft_slashnol()
{
	char *c;
	t_str *new;

	c = ft_strspace(0, 0);
	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		return ;
	new->next = NULL;
	new->string = c;
	new->counchar = 1;
	return (ft_strlistadd_end(&g_str, new));
}

void	ft_c_wild(t_flag *flag)
{
	if (flag->wild > 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild - 1,
													  flag->zero)));
}

void	func_c(size_t i, const char *fr, va_list str)
{
	t_flag *flag;
	char *c;

	flag = ft_flag(fr, i, '%');
	c = ft_strnew(1);
	c[0] = va_arg(str, int);
	if (flag->min)
	{
		if (c[0] == '\0')
			ft_slashnol();
		flag->zero = 0;
		ft_strlistadd_end(&g_str, newnode(c));
	}
	ft_c_wild(flag);
	if (flag->min == 0)
	{
		if (c[0] == '\0')
			ft_slashnol();
		ft_strlistadd_end(&g_str, newnode(c));
	}
	free(flag);
}