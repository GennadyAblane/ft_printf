/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:58:14 by ablane            #+#    #+#             */
/*   Updated: 2020/01/24 11:09:34 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlenpf(unsigned long long int a, unsigned long long int m)
{
	int	z;

	z = 0;
	while (a != 0)
	{
		a = a / m;
		z++;
	}
	if(z == 0)
		z = 1;
	return (z);
}

char	*ft_to_mat(unsigned long long int a, int i, unsigned long long int m)
{
	char			sexteen[] = "0123456789abcdefghijklmnopqrstuvwxyz\0";
	//todo ABCDEFGHIJKLMNOPQRSTUVWXYZ для больших букв
	char 			*str;
	unsigned long long int	p;
	unsigned long long int	q;

	str = ft_strspace((size_t)i, 0);
	q = a;
	if (a == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	while (a != 0 && i > 0)
	{
		q = a / m;
		p = a - (q * m);
		str[--i] = sexteen[p];
		a = q;
	}
	return (str);
}

int	ft_correct_input_for_p(const char *fr, size_t i)
{
	while (fr[i] != 'p')
	{
		if (fr[i] == '-' || (fr[i] >= '0' && fr[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

void	func_p(size_t i, const char *fr, va_list str)
{
	unsigned long long int u;
	char *c;
	int len;
	int w;
	int m;

	u = va_arg(str, unsigned long long int);
	if (ft_correct_input_for_p(fr, i))
		return;
	if ((m = ft_flag_mi_zer(fr, i)) > 0)
		i++;
	len = ft_intlenpf(u, 16);
	w = ret_int(fr, i);
	if (len < w && m < 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(w - (len + 2), 0)));
	ft_strlistadd_end(&g_str, newnode("0x"));
	ft_strlistadd_end(&g_str, newnode(ft_to_mat(u, len, 16)));
	if (len < w && m > 0)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(w - (len + 2), 0)));
}