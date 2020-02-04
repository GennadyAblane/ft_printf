/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:35:34 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 09:32:24 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void	ft_u_left(ssize_t len, t_flag *flag, char *p)
{
	if (flag->wild > flag->accuracy && flag->wild >= len)
		ft_max_wild(len, 0, flag, p);
	else if (flag->accuracy <= len && flag->wild <= len)
		ft_no_ac_and_wild(len, 0, flag, p);
	else if (flag->accuracy > len && flag->accuracy > flag->wild)
		ft_max_accuracy(len, 0, flag, p);
}

void	ft_u_right(ssize_t len, t_flag *flag, char *p)
{
	if (flag->wild > flag->accuracy && flag->wild >= len)
		ft_max_wild(len, 0, flag, p);

	if (flag->accuracy > len && flag->accuracy > flag->wild)
		ft_max_accuracy(len, 0, flag, p);

	if (flag->accuracy <= len && flag->wild <= len)
		ft_no_ac_and_wild(len, 0, flag, p);
}

char	*ft_parsing_act_u(ssize_t len, t_flag *flag, char *p)
{
	if(flag->reshotka && flag->specif != 'd')
	{
		p = ft_octothorpe(p, len);
		len = ft_strlen(p);
	}
	if (flag->min == 0)
		ft_u_right(len, flag, p);
	if (flag->min == 1)
		ft_u_left(len, flag, p);
	return (p);
}

void	func_u(size_t i, const char *fr, va_list str)
{
	unsigned long long int u;
	t_flag	*flag;
	char *p;
	int len;

	flag = ft_flag(fr, i, 'u');
	if(flag->l || flag->ll || flag->h || flag->hh)
		p = ft_signed_int(flag, str, 10);
	else
	{
		u = va_arg(str, unsigned long long int);
		p = ft_itoa_base(u, 10, 0);
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
	p = ft_parsing_act_u(len, flag, p);
	if (flag->min == 0)
		ft_strlistadd_end(&g_str, newnode(p));
	free(flag);
}