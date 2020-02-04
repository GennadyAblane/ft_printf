/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:07:11 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intchar(int n)
{
	int	b;

	b = n % 10;
	if (n < 0)
		return (b * -1);
	return (b);
}

static char	*ft_masintchar(char *p, int len, int n)
{
	int	i;

	i = len - 1;
	if (n < 0)
	{
		p[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		p[0] = '0';
	while (n != 0)
	{
		p[i--] = ft_intchar(n) + '0';
		n = n / 10;
	}
	p[len] = '\0';
	return (p);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		len;

	if (n == 0)
	{
		p = ft_memalloc(2);
		return (ft_masintchar(p, 1, 0));
	}
	len = (ft_intlen(n));
	p = ft_memalloc(len + 1);
	if (!p)
		return (NULL);
	return (ft_masintchar(p, len, n));
}
