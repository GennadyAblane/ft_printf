/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:21:51 by ablane            #+#    #+#             */
/*   Updated: 2020/01/29 12:34:23 by ablane           ###   ########.fr       */
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

void ft_add_width(size_t i, size_t o)
{
	t_str *start;
	char *new;
	size_t n;
	size_t p;

	n = 0;
	p = 0;
	start = g_str;
	while (start->next)
		start = start->next;
	if (!(new = ft_strspace(i, o)))
		return ;
	while (start->string[p] != '\0')
	{
		if (o == 1 || o == 3)
			new[n++] = start->string[p++];
		else
		{
			n = i - start->counchar;
			new[n++] = start->string[p++];
		}
	}
	start->counchar = i;
	start->string = new;
}

int count(t_str *tmp, size_t n)
{
	while (tmp->next)
		tmp = tmp->next;
	if (n > tmp->counchar)
		return (1);
	return (0);
}

int	ft_correct_input_for_c(const char *fr, size_t i)
{
	while (fr[i] != 'c')
	{
		if (fr[i] == '-' || (fr[i] >= '0' && fr[i] <= '9'))
			i++;
		else
			return (1);
	}
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


void	ft_last_proc_char(size_t n, size_t p)
{
	size_t w;
	char *c;

	w = count(g_str, n);
	if (w > 0)
	{
		if (p > 0)
			ft_strlistadd_end(&g_str, newnode(ft_strspace(n - 1, p)));
		if (p == 0)
		{
			ft_strlistadd_penultimate(&g_str, newnode(ft_strspace(n - 1, p)));
			ft_slashnol();
		}
	}
//	ft_add_width(n, p);

}

void	func_c(size_t i, const char *fr, va_list str)
{
	size_t n;
	size_t p;
	char *c;

	p = 0;
	n = 0;
	c = ft_strspace(1, 0);
	c[0] = va_arg(str, int);
	if (ft_correct_input_for_c(fr, i))
		return (free(c));
	p = ft_flag_mi_zer(fr, i);
	if(fr[i] != 'c')
		i = ft_point_p (fr, p, i, 'c');
	while ((fr[i] >= '0') && (fr[i] <= '9'))
	{
		n = n * 10 + (fr[i] - '0');
		i++;
	}
	if (p == 0 && n > 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(n - 1, 0)));
	if (c[0] == '\0')
		ft_slashnol();
	if (c[0] != '\0')
		ft_strlistadd_end(&g_str, newnode(c));
	if (p > 0 && n > 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(n - 1, 0)));
}