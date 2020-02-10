/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:15:28 by ablane            #+#    #+#             */
/*   Updated: 2020/02/10 15:24:34 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_recount(char *p, t_flag *flag)
{
	char *new;
	int	i;
	int len;


	len = ft_strlen(p);//todo len = ft_strlen(p)-1
	i = len;
	if(len == 1 && p[len] == '\0' && p[0] == '9')
	{
		new = ft_strspace(len, 2);
		new[0] = '1';
		return (new);
	}
	if (len == 1 && (p[len] <= '9' && p[len] >= '5'))
	{
		if(p[0] == '9')
		{
			new = ft_strspace(len + 1, 2);
			new[0] = '1';
			return (new);
		}
		p[0] = p[0] + 1;
		p[1] = '\0';
		new = p;
	}
	else
	{
		i = --len;
		if (p[len] >= '5' && p[len] <= '9')
		{
			p[len] = '9';
			while (p[i] == '9' && i > -1)
				p[i--] = '0';
			p[i] = p[i] + 1;
		}
		if(len == 0)
			return (p);
		p[len] = '\0';
		new = ft_strnew(len);
		new = ft_strncpy(new, p, len);
		free(p);
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

	if(flag->accuracy == 0)
		return (p);
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

char	*ft_add_accuracy(char *p, t_flag *flag)
{
	char *new;
	int len;
	int i;

	len = ft_strlen(p);
	if (len < flag->accuracy + 1)
	{
		i = flag->accuracy + 1;
		new = ft_strspace(i, 2);
		while (len > -1)
		{
			new[i] = p[len];
			len--;
			i--;
		}
		free(p);
		return (new);
	}
	return (p);
}

char	*ft_check_five(char *p)
{
	int		len;
	char	*new;
	int 	i;

	len = ft_strlen(p) - 1;
	if (p[len] >= '5' && p[len] <= '9')
	{
		if(p[len - 1] == '9')
			p[len - 1] = 56;//todo ???
		p[len - 1] = p[len - 1] + 1;
		p[len] = '0';//todo ???
		if (p[len - 1] == '5')
		{
			i = p[len - 2] - 48;
			if (((i + 1) % 2) != 0)
				p[len - 2] = p[len - 2] - 1;
		}
		else if (p[len] >= '5' && p[len] <= '9')
			p[len - 1] = '9';
	}
//	if (p[len] >= '0' && p[len] <= '4')
//		p[len - 1] = '0';
	new = ft_strnew(len);
	new = ft_strncpy(new, p , len);
	return (new);
}

char	*ft_flot_str(long double u, t_flag *flag)
{
	char	*p;
	long long int point;
	int len;

	point = 0;
//todo	if(u == целое число,   u - (int)u *10 в максимальной степени)
	while (point < flag->accuracy)
	{
		u = u * 10;
		point++;
	}
	u = u * 10;
	u = u * 10;//todo лишняя
	p = ft_un_itoa_base((unsigned long long int)u, 10, 0);
	p = ft_check_five(p); //todo  проверка на 5 или 4
	p = ft_add_accuracy(p, flag);
	p = ft_recount(p, flag);
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