/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:21:45 by ablane            #+#    #+#             */
/*   Updated: 2020/02/05 12:36:58 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t ft_find_min(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.' && ((fr[i] <= '1') || (fr[i] > '9')))
	{
		if (fr[i] == '-')
			return(1);
		i++;
	}
	return (0);
}

ssize_t ft_find_plus(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.' && ((fr[i] <= '1') || (fr[i] > '9')))
	{
		if (fr[i] == '+')
			return(1);
		i++;
	}
	return (0);
}

ssize_t ft_find_zero(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.')
	{
		if (fr[i] > 48 && fr[i] < 58)
			return (0);
		if (fr[i] == '0')
			return(2);
		i++;
	}
	return (0);
}

ssize_t ft_find_space(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.' && ((fr[i] <= '1') || (fr[i] > '9')))
	{
		if (fr[i] == ' ')
			return(1);
		i++;
	}
	return (0);
}

ssize_t ft_find_accuracy(const char *fr, size_t i, char spec)
{
	ssize_t n;

	n = -1;
	while (fr[i] != spec)
	{
		if (fr[i] == '.')
		{
			n = 0;
			i++;
			if ((fr[i] >= '0') && (fr[i] <= '9'))
				n = ft_atoi(&fr[i]);
			return (n);
		}
		i++;
	}
	return (n);
}
ssize_t ft_find_wild(const char *fr, size_t i, char spec)
{
	ssize_t n;

	n = -1;
	while (fr[i] != spec && fr[i] != '.')
	{
		if ((fr[i] > '0') && (fr[i] <= '9'))
		{
			n = ft_atoi(&fr[i]);
			return (n);
		}
		i++;
	}
	return (n);
}
ssize_t ft_find_reshotka(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.' && ((fr[i] <= '1') || (fr[i] > '9')))
	{
		if (fr[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

ssize_t ft_find_l(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec)
	{
		if (fr[i] == 'l' && fr[i + 1] != 'l')
			return(1);
		if (fr[i] == 'l' && fr[i + 1] == 'l')
			i++;
		i++;
	}
	return (0);
}

ssize_t ft_find_L(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.' && ((fr[i] <= '1') || (fr[i] > '9')))
	{
		if (fr[i] == 'L')
			return(1);
		i++;
	}
	return (0);
}

ssize_t ft_find_h(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.' && ((fr[i] <= '1') || (fr[i] > '9')))
	{
		if (fr[i] == 'h' && fr[i + 1] != 'h')
			return(1);
		if (fr[i] == 'h' && fr[i + 1] == 'h')
			i++;
		i++;
	}
	return (0);
}

ssize_t ft_find_ll(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec)
	{
		if (fr[i] == 'l' && fr[i + 1] == 'l')
			return(1);
		i++;
	}
	return (0);
}

ssize_t ft_find_hh(const char *fr, size_t i, char spec)
{
	while (fr[i] != spec && fr[i] != '.' && ((fr[i] <= '0') || (fr[i] >= '9')))
	{
		if (fr[i] == 'h' && fr[i + 1] == 'h')
			return(1);
		i++;
	}
	return (0);
}
