/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:20:31 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 09:32:14 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "ft_printf.h"

static int	ft_memsize(long long int n, int base)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static char		*ft_fillnum(char *str, long long int n, size_t size, int base)
{
	unsigned long long int	nb;
	char 					s[] = "0123456789abcdef";

	nb = n;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[--size] = s[nb % base];
		nb = nb / base;
	}
	return (str);
}

char			*ft_itoa_base(long long int n, int base, int l_size)
{
	char		*str;
	size_t		size;
	int			i;

	size = ft_memsize(n, base);
	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	str = ft_fillnum(str, n, size, base);
	i = 0;
	if (l_size == 1)
		while (str[i])
		{
			if (ft_isalpha(str[i]))
				str[i] = (char)ft_toupper(str[i]);
			i++;
		}
	return (str);
}