/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:20:16 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 09:36:02 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void find_function2(char s, int p, const char *fr, va_list str)
{
	if (s == 's')
		func_s(p, fr, str);
	if (s == 'p')
		func_p(p, fr, str);
	if (s == 'o')
		func_o(p, fr, str);
	if (s == 'u')
		func_u(p, fr, str);
/*	if (s == 'b')
		func_b(p, fr, str);
	if (s == 'r')
		func_r(p, fr, str);
	if (s == 'k')
		func_k(p, fr, str);
*/	if (s == '%')
		func_percent(p, fr, str);
}

void find_function(char s, int p, const char *fr, va_list str)
{
	if (s == 'c')
		func_c(p, fr, str);
	if (s == 'd' || s == 'i')
		func_di(p, fr, str);
	if (s == 'x' || s == 'X')
		func_x(p, fr, str);
/*	if (s == 'f')
		func_f(p, fr, str);
	if (s == 'e')
		func_e(p, fr, str);
	if (s == 'g')
		func_g(p, fr, str);
*/	else
		find_function2(s, p, fr, str);
}

int	specification(int p, const char *fr, va_list str)
{
	int n;
	int i;
	char spec[] = ALL_SPEC;

	i = p;
	while(fr[i] != '\0')
	{
		i = p;
		while (fr[i] != '\0')
		{
			n = 0;
			while (fr[i] != spec[n] && spec[n] != '\0')
				n++;
			if (fr[i] == spec[n] && spec[n] != '\0')
			{
				find_function(spec[n], p, fr, str);
				return (between(fr, ++i));
			}
			i++;
		}
		return (between(fr, p));
	}
	return (i);
}

int	ft_precentaddlist(int i)
{
	char *c;

	c = ft_strspace(1, 0);
	c[0] = '%';
	ft_strlistadd_end(&g_str, newnode(c));
	return (++i);
}

void 	percent(int i, const char *fr, va_list str)
{
	while (fr[i] != '\0')
	{
		if (fr[i] != '%')
		{
			i = between(fr, i);
		}
		while (fr[i] == '%')
		{
			if (fr[++i] != '\0')
				i = specification(i, fr, str);
		}
	}
}

int	ft_printf(const char *fr, ...)
{
	size_t i;
	va_list arg;

	i = 0;
	va_start(arg, fr);
	percent(i , fr, arg);
	va_end(arg);
	return (print_string());
}