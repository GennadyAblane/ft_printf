/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:15:28 by ablane            #+#    #+#             */
/*   Updated: 2020/02/06 15:58:03 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_recount(char *p, int len)
{
	char *new;
	int	i;

	i = len;
	if (len == 0 && p[len] == '9')
	{
		p[len] = '1';
		new = p;
	}
	else
	{
		while (p[i] == '9' && i > -1)
			p[i--] = '0';
		p[i] = p[i] + 1;
		new = ft_strnew(len);
		new = (char *) ft_memcpy(new, p, len);
		new[len] = '\0';
	}
	return (new);
}

char *ft_less_than_one(char *p, long long int point, t_flag *flag, int len)
{
	char *new;
	int i;

	i = 0;
	new = ft_strspace(point, 2);
	while (len != -1)
		new[point--] = p[len--];
	return (new);
}

char *ft_point_float(char *p, t_flag *flag, int len, long long int point)
{
	int i;
	char *new;

	point--;
	if (len < flag->accuracy)
	{
		p = ft_less_than_one(p, point, flag, len);
		len = ft_strlen(p);
	}
	new = ft_strnew(len + 1);
	i = 0;
	while (len - point != 0)
	{
		new[i] = p[i];
		i++;
		len--;

	}
	new[i] = '.';
	while (point)
	{
		new[i + 1] = p[i];
		i++;
		point--;
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
	p = ft_itoa_base((long long int)u, 10, 0);
	len = ft_strlen(p);
	p = ft_recount(p, --len);

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