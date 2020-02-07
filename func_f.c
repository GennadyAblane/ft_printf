/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:15:28 by ablane            #+#    #+#             */
/*   Updated: 2020/02/07 11:49:35 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_recount(char *p)
{
	char *new;
	int	i;
	int len;

	len = ft_strlen(p) - 1;//todo len = ft_strlen(p)
	i = len;
	if (len == 1 && p[len] == '9')
	{
		p[0] = '1';
		p[1] = '\0';
		new = p;
	}
//	else if (p[len] > '4')
//	{
//		if()
//	}
	else
	{
		while (p[i] == '9' && i > -1)
			p[i--] = '0';
		p[i] = p[i] + 1;
		p[len - 1] = '\0';
		new = ft_strnew(len - 2);
		new = ft_strcpy(new, p);
	}
	return (new);
}

char *ft_less_than_one(char *p, t_flag *flag, int len)
{
	char *new;
	int i;


	i = flag->accuracy + 1;
	new = ft_strspace(i, 2);
	while (len != -1)
		new[i--] = p[len--];
	return (new);
}

char *ft_point_float(char *p, t_flag *flag, int len, long long int point)
{
	int i;
	char *new;

	if(len < point)
	{
		p = ft_less_than_one(p, flag, len);
		len = ft_strlen(p);
	}
	i = 0;
	new = ft_strspace(len + 1, 2);
	point--;
	while (i != len - point)
	{
		new[i] = p[i];
		i++;
	}
	new[i] = '.';
	while (p[i])
	{
		new[i + 1] = p[i];
		i++;
	}
	return (new);
}

char	*ft_flot_str(long double u, t_flag *flag)
{
	char	*p;
	long long int point;
	int len;

	point = 0;
	while (point < flag->accuracy)
	{
		u = u * 10;
		point++;
	}
	u = u * 10;
	u = u * 10;
	p = ft_itoa_base((long long int)u, 10, 0);
	p = ft_recount(p);
	len = ft_strlen(p);

	p = ft_point_float(p, flag, len, ++point);
	return (p);
}

void	func_f(size_t i, const char *fr, va_list str)
{
	long double u;
	t_flag	*flag;
	char *p;

	flag = ft_flag(fr, i, 'f');
	if (flag->accuracy == -1)
		flag->accuracy = 6;
	u = (long double)va_arg(str, double);
	if (u < 0)
	{
		flag->str_min = 1;
		u = u * -1;
		ft_strlistadd_end(&g_str, newnode("-"));
	}
	p = ft_flot_str(u, flag);
	ft_strlistadd_end(&g_str, newnode(p));
	free(flag);
}