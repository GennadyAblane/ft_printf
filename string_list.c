/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:22 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 09:51:50 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//ft_strlistadd_end(&g_str, create_newnode(str));

t_flag *ft_flag(const char *c, size_t i, char spec)
{
	t_flag *new;

	new = (t_flag *) malloc(sizeof(t_flag));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->accuracy = ft_find_accuracy(c, i, spec);
	new->wild = ft_find_wild(c, i, spec);
	new->min = ft_find_min(c, i, spec);
	new->plus = ft_find_plus(c, i, spec);
	new->zero = ft_find_zero(c, i, spec);
	new->space = ft_find_space(c, i, spec);
	new->reshotka = ft_find_reshotka(c, i, spec);
	new->l = ft_find_l(c, i, spec);
	new->ll = ft_find_ll(c, i, spec);
	new->L = ft_find_L(c, i, spec);
	new->h = ft_find_h(c, i, spec);
	new->hh = ft_find_hh(c, i, spec);
	new->str_min = 0;
	new->specif = spec;
	return (new);
}

t_str *newnode(char *c)
{
	t_str *new;

	new = (t_str *)malloc(sizeof(t_str));
	if (!new)//todo !new
		return (NULL);
	new->next = NULL;
	new->string = c;
	new->counchar = ft_strlen(c);
	return (new);
}

void ft_strlistadd_penultimate(t_str **alst, t_str *new)
{
	t_str *tmp;
	t_str *penultimate;
	size_t i;

	i = 0;
	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	penultimate = *alst;
	while (penultimate->next)
	{
		penultimate = penultimate->next;
		i++;
	}
	if (i < 1)
		ft_strlistadd_end(alst, newnode("\0"));
	tmp = *alst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = new;
	tmp = tmp->next;
	tmp = penultimate;

}

void	ft_strlistadd_end(t_str **alst, t_str *new)
{
	t_str *tmp;

	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int print_string(void)
{

	size_t ret;

	ret = 0;
	while (g_str)
	{
		ret = ret + g_str->counchar;
		write(1, g_str->string, g_str->counchar);
		g_str = g_str->next;
	}
	return ((int)ret);
}

size_t	between(const char *fr, size_t i)
{
	char *c;

	c = ft_strnew(0);
	while(fr[i] != '%' && fr[i] != '\0')
	{
		c = ft_line_numbers(c, fr[i++]);
	}
	ft_strlistadd_end(&g_str, newnode(c));
//	if (c == '\0')
//		return (++i);
	return (i);
}