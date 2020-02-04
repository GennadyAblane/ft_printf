/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:49:59 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_halper(const char *s)
{
	char	*p;
	int		m;

	m = 0;
	p = (char*)s;
	while (p[m] == '\n' || p[m] == '\t' || p[m] == '\v'
			|| p[m] == '\r' || p[m] == '\f' || p[m] == ' ')
		m++;
	return (&p[m]);
}

static int	ft_minus(char *p)
{
	int		mi;

	mi = 1;
	if (*p == '-')
		mi = -1;
	return (mi);
}

int			ft_atoi(const char *s)
{
	int		n;
	int		mi;
	int		l;
	char	*p;

	mi = 1;
	n = 0;
	l = 0;
	p = ft_halper(s);
	if (*p == '+' || *p == '-')
		mi = ft_minus(p++);
	while (*p >= '0' && *p <= '9')
	{
		n = (n * 10) + (*p - 48);
		p++;
		l++;
	}
	if (l > 19)
	{
		if (mi == -1 || n > 0)
			return (0);
		if (n < 0)
			return (-1);
	}
	return (n * mi);
}
