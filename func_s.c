/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:24:04 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 09:32:24 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ret_int(const char *fr, size_t i)
{
	int	n;

	n = 0;
	while ((fr[i] >= '0') && (fr[i] <= '9'))
	{
		n = n * 10 + (fr[i] - '0');
		i++;
	}
	return (n);
}

char	*ft_str_cut(char *c, int s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(s);
	while (i < s)
	{
		tmp[i] = c[i];
		i++;
	}
	return (tmp);
}

size_t	ret_size_t(const char *fr, size_t i)
{
	while ((fr[i] >= '0') && (fr[i] <= '9'))
		i++;
	return (i - 1);
}

char	*ft_add_space_min(char *c, int w, int m, int len)
{
	char	*tmp;
	int 	i;

	i = 0;
	tmp = ft_strspace(w, 0);
	if (m > 0)
	{
		while (c[i] != '\0')
		{
			tmp[i] = c[i];
			i++;
		}
	}
	else
	{
		while (c[i] != '\0')
			tmp[w++ - len] = c[i++];
	}
	return (tmp);
}

char	*ft_align(char *c, int w, int s, int m)
{
	int len;

	len = ft_strlen(c);
	if (len > s && s >= 0)
	{
		c = ft_str_cut(c, s);
		len = s;
	}
	if (len < w)
	{
		c = ft_add_space_min(c, w, m, len);
	}
	return (c);
}

char *ft_whild_percision(char *c, const char *fr, size_t i, char spec)
{
	int w;
	int	s;
	int m;

	w = -1;
	s = -1;
	m = 0;
	if (fr[i] == '-')
		m = ft_flag_mi_zer(fr, i++);
	while (fr[i] != spec)
	{
		if (fr[i] == '.')
		{
			s = ret_int(fr, ++i);
			i = ret_size_t(fr, i);
		}
		else
		{
			w = ret_int(fr, i);
			i = ret_size_t(fr, i);
		}
		i++;
	}
	return(ft_align(c, w, s, m));
}

int	ft_correct_input_for_s(const char *fr, size_t i)
{
	while (fr[i] != 's')
	{
		if (fr[i] == '-' || fr[i] == '.' || (fr[i] >= '0' && fr[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

char	*ft_cut_accuracy(char *p, ssize_t accuracy)
{
	ssize_t i;
	char *new;

	i = 0;
	new = ft_strnew(accuracy);
	if (!new)
		return (NULL);
	while(i < accuracy)
	{
		new[i] = p[i];
		i++;
	}
	new[accuracy] = '\0';
	return(new);
}
void	func_s(size_t i, const char *fr, va_list str)
{
	ssize_t	n;
	t_flag	*flag;
	char	*p;

	flag = ft_flag(fr, i, 's');
	p = va_arg(str, char*);
	if (!p)
		p = "(null)\0";
	n = ft_strlen(p);
	if (n > flag->accuracy && flag->accuracy > -1)
	{
		p = ft_cut_accuracy(p, flag->accuracy);
		n = flag->accuracy;
	}
	if (flag->min == 0 && flag->wild > n)
		ft_strlistadd_end(&g_str, newnode(ft_strspace((size_t)flag->wild - n,
				flag->zero)));
	ft_strlistadd_end(&g_str, newnode(p));
	if (flag->min == 1 && flag->wild > n)
		ft_strlistadd_end(&g_str, newnode(ft_strspace((size_t)flag->wild - n,
				1)));
	free(flag);
}