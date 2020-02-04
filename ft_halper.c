/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_halper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:19:42 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 09:32:14 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_flag_mi_zer(const char *fr, size_t i)
{
	size_t	p;
	size_t	c;

	p = 0;
	c = 0;
	while ((fr[i] == '-') || (fr[i] == '0'))
	{
		if (fr[i] == '-')
			p = 1;
		if (fr[i] == '0')
			c = 1;
		if (p == 1 && c == 1)
			return (3);
		i++;
	}
	if (p == 0 && c == 1)
		return (2);
	return (p);
}

size_t ft_point_p(const char *fr, size_t p, size_t i, char c)
{
	if (p != 0)
	{
		if (p == 1 || p == 2)
			i++;
		else
			i = i + 2;
	}
	while ((fr[i] < '0' || fr[i] > '9') && fr[i] != c)
	{
		i++;
	}
	return (i);
}

size_t	between_to_spase(const char *fr, size_t i)
{
	char *c;

	c = ft_strnew(0);
	while(fr[i] != ' ' && fr[i] != '\0')
		c = ft_line_numbers(c, fr[i++]);
	ft_strlistadd_end(&g_str, newnode(c));
	return (i);
}