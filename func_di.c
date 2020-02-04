/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:22:47 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 10:01:33 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *revstr(char *c)
{
	size_t	a;
	size_t	z;
	char	n;

	a = 0;
	if (c[0] == '\0')
		return (c);
	z = ft_strlen(c) - 1;
	while (a != z && a < z)
	{
		n = c[a];
		c[a++] = c[z];
		c[z--] = n;
	}
	return (c);
}

char *ft_line_numbers(char *in, char c)
{
	char *line;
	size_t i;

	i = ft_strlen(in) + 1;
	line = ft_strnew(i);
	line = ft_strcpy(line, in);
	line[i - 1] = c;
	line[i] = '\0';
	free(in);
	return(line);
}

char *ft_nb(int nb, char *c)
{
	while (nb > 0)
	{
		if (nb > 9)
		{
			c = ft_line_numbers(c, nb % 10 + '0');
			nb = nb / 10;
		}
		else if (nb < 10 && nb >= 0)
		{
			c = ft_line_numbers(c, nb + '0');
			nb = 0;
		}
	}
	return (c);
}

char    *ft_putpfnbr(const char *fr,size_t p, int nb) //todo походу не нужно!
{
	char *c;
	size_t i;

	i = 0;
	if (nb == -2147483648)
		return (c = "-2147483648");
	c = ft_strnew(0);
	if (nb == 0)
		c = ft_line_numbers(c, nb + '0');
	if (nb < 0)
	{
		nb = nb * (-1);
		i++;
	}
	c = ft_nb(nb, c);
	if (i == 1)
		c = ft_line_numbers(c, '-');
	c = revstr(c);
	return (c);
}

void ft_add_space(size_t i) //todo походу не нужно!
{
	t_str *start;
	char *new;
	size_t n;
	size_t p;

	n = 0;
	p = 0;
	start = g_str;
	while (start->next)
		start = start->next;
	new = ft_strnew(i + ft_strlen(start->string));
	while (n != i)
	{
		if (n < (i - start->counchar))
			new[n++] = 32;
		else
			new[n++] = start->string[p++];
	}
	start->counchar = i;
	start->string = new;
}

char	*ft_cut_str_zero(char *p)
{
	ssize_t len;
	char	*new;

	len = ft_strlen(p);
	new = ft_strspace(len - 1, 2);
	if (!new)
		return (NULL);
	while (len - 1 != 0)
	{
		new[len - 2] = p[len - 1];
		len--;
	}
	return (new);
}

char *ft_plusminus(t_flag *flag)
{
	char *c;

	c = ft_strnew(1);
	if(!c)
		return (NULL);
	if (flag->str_min == 1)
		c[0] = '-';
	else
		c[0] = '+';
	return (c);
}

void ft_max_wild_min(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	if (z)
		ft_strlistadd_end(&g_str, newnode(ft_plusminus(flag)));
	if (flag->accuracy > len)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->accuracy - len,
				2)));
	ft_strlistadd_end(&g_str, newnode(p));
	if (flag->wild > flag->accuracy + z && flag->wild > len + z + flag->space)
	{
		if(flag->accuracy > -1 && flag->accuracy > len + z)
			ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild -
			(flag->accuracy + z + flag->space),1)));
		else
			ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild - (len +
			z + flag->space),1)));
	}
	else
		ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild - (len + z),
				1)));
}

void ft_max_wild_nomin(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	if (flag->zero)
	{
		if (z)
			ft_strlistadd_end(&g_str, newnode(ft_plusminus(flag)));
		ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild - (len + z +
		flag->space),2)));
	}
	else
	{
		if (flag->accuracy > len)
			ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild -
			(flag->accuracy + z + flag->space),1)));
		else
			ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild - (len +
			z + flag->space), 1)));
		if (z)
			ft_strlistadd_end(&g_str, newnode(ft_plusminus(flag)));
		if (flag->accuracy > len)
			ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->accuracy - len, 2)));
	}
}
void ft_max_wild(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	if (flag->min == 0)
		ft_max_wild_nomin(len, z, flag, p);
	if (flag->min == 1)
		ft_max_wild_min(len, z, flag, p);
}

void	ft_max_accuracy(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	char *d;

	d = ft_strspace(flag->accuracy - len , 2);
	if (z)
		ft_strlistadd_end(&g_str, newnode(ft_plusminus(flag)));
	ft_strlistadd_end(&g_str, newnode(d));
	if(flag->min)
		ft_strlistadd_end(&g_str, newnode(p));
}

void	ft_no_ac_and_wild(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	if (z)
		ft_strlistadd_end(&g_str, newnode(ft_plusminus(flag)));
	if (flag->min)
		ft_strlistadd_end(&g_str, newnode(p));
}

void	ft_di_right(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	if (flag->wild > flag->accuracy && flag->wild >= len + z)
		ft_max_wild(len, z, flag, p);

	if (flag->accuracy > len && flag->accuracy > flag->wild)
		ft_max_accuracy(len, z, flag, p);

	if (flag->accuracy <= len && flag->wild <= len)
		ft_no_ac_and_wild(len, z, flag, p);
}

void	ft_di_left(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	if (flag->wild > flag->accuracy && flag->wild >= len + z)
		ft_max_wild(len, z, flag, p);
	else if (flag->accuracy <= len && flag->wild <= len + z)
		ft_no_ac_and_wild(len, z, flag, p);
	else if (flag->accuracy > len && flag->accuracy > flag->wild)
		ft_max_accuracy(len, z, flag, p);
}

void	ft_flag_spase(ssize_t len, ssize_t z, t_flag *flag, char *p)
{
	if (!z && flag->wild <= len)
		ft_strlistadd_end(&g_str, newnode(" "));
	if (!z && flag->wild > len)
		ft_strlistadd_end(&g_str, newnode(" "));
	if (flag->wild == len || (z && flag->wild > len))
		flag->space = 0;

}

char *ft_signed_int(t_flag *flag, va_list str, int n)
{
	int p;

	p = 0;
	if (flag->specif == 'X')
		p = 1;
	if(flag->l)
		return (ft_itoa_base((long)va_arg(str, long), n, p));
	if(flag->ll)
		return(ft_itoa_base((long long int)va_arg(str, long long), n, p));
	if(flag->h)
		return(ft_itoa_base(va_arg(str, int), n, p)); //todo (short int)
	if(flag->hh)
		return(ft_itoa_base(va_arg(str, int), n, p));//todo (long)
	return (NULL);
}

char	ft_find_d_i(const char *fr, size_t i)
{
	while (fr[i] != 'i' && fr[i] != 'd')
		i++;
	if (fr[i] == 'd')
		return ('d');
	return ('i');
}
void func_di(size_t i, const char *fr, va_list str)
{
	signed long long int	len;
	ssize_t	z;
	t_flag	*flag;
	char	*p;
	char	specif;

	z = 0;
	specif = ft_find_d_i(fr, i);
	flag = ft_flag(fr, i, specif);
	if(flag->l || flag->ll || flag->h || flag->hh)
		p = ft_signed_int(flag, str, 10);
	else
		p = ft_itoa(va_arg(str, int));
	if (p[0] == '-')
	{
		p = ft_cut_str_zero(p);
		flag->str_min = 1;
	}
	len = ft_strlen(p);
	if (flag->plus || flag->str_min)
		z = 1;
	if(flag->space)
		ft_flag_spase(len, z, flag, p);
	if(flag->min || flag->accuracy > -1)
		flag->zero = 0;
	if (p[0] == '0' && (flag->accuracy == 0))
	{
		p[0] = 0;
		len--;
	}
	if (flag->min == 0)
		ft_di_right(len, z, flag, p);
	if (flag->min == 1)
		ft_di_left(len, z, flag, p);
	if (flag->min == 0)
		ft_strlistadd_end(&g_str, newnode(p));
	free(flag);
}