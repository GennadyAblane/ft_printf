/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:46:53 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 10:12:15 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_left(ssize_t len, t_flag *flag, char *p)
{
	if (flag->wild > flag->accuracy && flag->wild >= len)
		ft_max_wild(len, 0, flag, p);
	else if (flag->accuracy <= len && flag->wild <= len)
		ft_no_ac_and_wild(len, 0, flag, p);
	else if (flag->accuracy > len && flag->accuracy > flag->wild)
		ft_max_accuracy(len, 0, flag, p);
}

void	ft_x_right(ssize_t len, t_flag *flag, char *p)
{
	if (flag->wild > flag->accuracy && flag->wild >= len)
		ft_max_wild(len, 0, flag, p);

	if (flag->accuracy > len && flag->accuracy > flag->wild)
		ft_max_accuracy(len, 0, flag, p);

	if (flag->accuracy <= len && flag->wild <= len)
		ft_no_ac_and_wild(len, 0, flag, p);
}

char *ft_octothorpe_x(char *d, ssize_t len, int n)
{
	char *p;
	int i;
	char z;

	if (n == 0)
		z = 'x';
	else
		z = 'X';
	i = 2;
	if (d[0] == '0')
		return (d);
	p = ft_strnew(len + 2);
	p[0] = '0';
	p[1] = z;
	while(d[i - 2] != '\0')
	{
		p[i] = d[i - 2];
		i++;
	}
	free(d);
	return (p);
}

char	*ft_parsing_act_x(ssize_t len, t_flag *flag, char *p, int n)
{
	if(flag->reshotka && flag->specif != 'd')
	{
		p = ft_octothorpe_x(p, len, n);
		len = ft_strlen(p);
	}
	if (flag->min == 0)
		ft_x_right(len, flag, p);
	if (flag->min == 1)
		ft_x_left(len, flag, p);
	return (p);
}

int	ft_x(const char *fr, size_t i)
{
	while (fr[i] != 'x' && fr[i] != 'X')
		i++;
	if(fr[i] == 'X')
		return (1);
	return (0);
}

void	func_x(size_t i, const char *fr, va_list str)
{
	unsigned long long int u;//todo ковыряй x
	t_flag	*flag;
	char *p;
	int len;
	int n;

	n = ft_x(fr, i);
	if(n == 0)
		flag = ft_flag(fr, i, 'x');
	else if(n == 1)
		flag = ft_flag(fr, i, 'X');
	if(flag->l || flag->ll || flag->h || flag->hh)
		p = ft_signed_int(flag, str, 16);
	else
	{
		u = va_arg(str, unsigned long long int);
		p = ft_itoa_base(u, 16, n);
	}
	len = ft_strlen(p);
	if(flag->space)
		ft_flag_spase(len, 0, flag, p);
	if(flag->min || flag->accuracy > -1)
		flag->zero = 0;
	if (p[0] == '0' && (flag->accuracy == 0))
	{
		p[0] = 0;
		len--;
	}
	p = ft_parsing_act_x(len, flag, p, n);
	if (flag->min == 0)
		ft_strlistadd_end(&g_str, newnode(p));
	free(flag);
}