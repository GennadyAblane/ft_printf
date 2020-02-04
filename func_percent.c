/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:23:20 by ablane            #+#    #+#             */
/*   Updated: 2020/01/27 12:25:13 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_correct_input_for_percent(const char *fr, size_t i)
{
	while (fr[i] != '%')
	{
		if (fr[i] == '-' || (fr[i] >= '0' && fr[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

void	func_percent(size_t i, const char *fr, va_list str)
{
	size_t n;
	size_t p;
	char *c;

	p = 0;
	n = 0;
	c = ft_strspace(1, 0);
	c[0] = '%';
	if (ft_correct_input_for_percent(fr, i))
		return (free(c));
	p = ft_flag_mi_zer(fr, i);
	if (fr[i] != '%')
		i = ft_point_p(fr, p, i, '%');
	while ((fr[i] >= '0') && (fr[i] <= '9'))
	{
		n = n * 10 + (fr[i] - '0');
		i++;
	}
	if (p == 2 && n > 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(n - 1, 2)));
	if (p == 0 && n > 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(n - 1, 0)));
	if (c[0] != '\0')
		ft_strlistadd_end(&g_str, newnode(c));
	if ((p == 1 || p == 3) && n > 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(n - 1, 0)));
}