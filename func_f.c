/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:15:28 by ablane            #+#    #+#             */
/*   Updated: 2020/02/11 13:27:39 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_recount(char *p, t_flag *flag)
{
	char *new;
	int	i;
	int len;


	len = ft_strlen(p);//todo len = ft_strlen(p)-1
	i = len;
	if(len == 1 && p[len] == '\0' && p[0] == '9')
	{
		new = ft_strspace(len, 2);
		new[0] = '1';
		return (new);
	}
	if (len == 1 && (p[len] <= '9' && p[len] >= '5'))
	{
		if(p[0] == '9')
		{
			new = ft_strspace(len + 1, 2);
			new[0] = '1';
			return (new);
		}
		p[0] = p[0] + 1;
		p[1] = '\0';
		new = p;
	}
	else
	{
		i = --len;
		if (p[len] >= '5' && p[len] <= '9')
		{
			p[len] = '9';
			while (p[i] == '9' && i > -1)
				p[i--] = '0';
			p[i] = p[i] + 1;
		}
		if(len == 0)
			return (p);
		p[len] = '\0';
		new = ft_strnew(len);
		new = ft_strncpy(new, p, len);
		free(p);
	}
	return (new);
}

char *ft_less_than_one(char *p, t_flag *flag, int len)
{
	char *new;
	int i;


	i = flag->accuracy + 1;
	new = ft_strspace(i, 2);
	while (len != -1)
		new[i--] = p[len--];
	return (new);
}

char *ft_point_float(char *p, t_flag *flag, int len, long long int point)
{
	int i;
	char *new;

	if(flag->accuracy == 0)
		return (p);
	if(len < point)
	{
		p = ft_less_than_one(p, flag, len);
		len = ft_strlen(p);
	}
	i = 0;
	new = ft_strspace(len + 1, 2);
	point--;
	while (i != len - point)
	{
		new[i] = p[i];
		i++;
	}
	new[i] = '.';
	while (p[i])
	{
		new[i + 1] = p[i];
		i++;
	}
	return (new);
}

char	*ft_add_accuracy(char *p, t_flag *flag)
{
	char *new;
	int len;
	int i;

	len = ft_strlen(p);
	if (len < flag->accuracy + 1)
	{
		i = flag->accuracy + 1;
		new = ft_strspace(i, 2);
		while (len > -1)
		{
			new[i] = p[len];
			len--;
			i--;
		}
		free(p);
		return (new);
	}
	return (p);
}

char	*ft_check_five(char *p)
{
	int		len;
	char	*new;
	int 	i;

	len = ft_strlen(p) - 1;
	if (p[len] >= '5' && p[len] <= '9')
	{
		if(p[len - 1] == '9')
			p[len - 1] = 56;//todo ???
		p[len - 1] = p[len - 1] + 1;
		p[len] = '0';//todo ???
		if (p[len - 1] == '5')
		{
			i = p[len - 2] - 48;
			if (((i + 1) % 2) != 0)
				p[len - 2] = p[len - 2] - 1;
		}
		else if (p[len] >= '5' && p[len] <= '9')
			p[len - 1] = '9';
	}
//	if (p[len] >= '0' && p[len] <= '4')
//		p[len - 1] = '0';
	new = ft_strnew(len);
	new = ft_strncpy(new, p , len);
	return (new);
}

char	*ft_fractional_roungding(char *p)
{
	int len;
	int i;

	len = ft_strlen(p) - 1;
	i = 0;
	if(p[len] >= '5' && p[len] <= '9')
	{
		p[len] = '9';
		while (p[len] == '9' && len > -1)
		{
			p[len--] = '0';
			i = 1;
		}
		if(i && len > -1)
		{
			p[len] = p[len] + 1;
		}
	}
	return (p);
}

char	*ft_add_one_int(char *integer)
{
	char	*new;
	char 	*tmp;
	int		len;
	int 	i;

	i = 0;
	len = ft_strlen(integer) - 1;
	if (integer[len] == '9' && len > -1)
	{
		while (integer[len] == '9' && len != -1)
		{
			integer[len--] = '0';
			i = 1;
		}
		if(integer[0] == '0' && len == -1 && i)
		{
			tmp = ft_strnew(1);
			tmp[0] = '1';
			new = ft_strjoin(tmp, integer);
			free(tmp);
			free(integer);
			return (new);
		}
	}
		integer[len] = integer[len] + 1;
	return (integer);
}

char	*ft_fraction_overflow(char *accur_frac, char *integer)
{
	int len;
	int i;

	len = ft_strlen(accur_frac) - 1;
	i = 0;
	if (accur_frac[len] >= '5' && accur_frac[len] <= '9')
	{
		accur_frac[len] = '9';
		while (accur_frac[len] == '9' && len > -1)
		{
			accur_frac[len--] = '0';
			i = 1;
		}
		if (i && len > -1)
		{
			accur_frac[len] = accur_frac[len] + 1;
		}
		if (accur_frac[0] == '0' && len == -1 && i)
			integer = ft_add_one_int(integer);
	}
	return (integer);
}

char	*ft_mode_integer(char *integer, long double u, t_flag *flag)
{
	unsigned long long int i;
	char					*fractional;
	char 					*accur_frac;
	int						max;

	max = 0;
	i = (unsigned long long int) u;
	u = u - i;

	while(max !=19)
	{
		u = u * 10;
		max++;
	}
	fractional = ft_un_itoa_base((unsigned long long int)u, 10, 0);
	max = ft_strlen(fractional);
	fractional = ft_strjoin(ft_strspace(19 - max, 2), fractional);
	fractional = ft_fractional_roungding(fractional);
	accur_frac= ft_strnew(flag->accuracy + 1);
	accur_frac = ft_strncpy(accur_frac, fractional, flag->accuracy + 1);
	integer = ft_fraction_overflow(accur_frac, integer);
	return (integer);
}

char 	*ft_integer_number(long double u, t_flag *flag)
{
	unsigned long long int i;
	char	*integer;

	i = (unsigned long long int) u;
	integer = ft_un_itoa_base(i, 10, 0);
	integer = ft_mode_integer(integer, u, flag);
	if(flag->accuracy > 0 || flag->reshotka)
		integer = ft_strjoin(integer, ".");
	return (integer);
}

char	*un_ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t s;

	s = 0;
	while (s < n && src[s] != '\0')
	{
		dest[s] = src[s];
		s++;
	}
	return (dest);
}

char	*ft_find_comma_float(long double u, t_flag *flag)
{
	char	*new;
	int		i;
	int 	len;

	i = 0;
	while (i != flag->accuracy)
	{
		u = u * 10;
		i++;
	}
	new = ft_un_itoa_base((unsigned long long int)u, 10, 0);
	len = ft_strlen(new);
	i = flag->accuracy - len;
	free(new);
	new = ft_strspace(i, 2);
	return (new);
}

char	*ft_fractional_number(long double u, t_flag *flag, char *integer)
{
	unsigned long long int i;
	char					*fractional;
	char 					*accur_frac;
	int						max;
	int 					len;

	max = 19;
	len = 0;
	i = (unsigned long long int) u;
	u = u - i;
	if (flag->accuracy > 16 && flag->accuracy < 19)
		max = flag->accuracy + 1;
	while(max != 0)
	{
		u = u * 10;
		max--;
		len++;
	}
	//todo определить сколько нулей перед числом для вывода точки
	fractional = ft_un_itoa_base((unsigned long long int)u, 10, 0);
	max = ft_strlen(fractional);
	if(flag->accuracy > 16 && flag->accuracy < 19)
		fractional = ft_strjoin(ft_strspace((flag->accuracy + 1) - max, 2),
				fractional);
	else
		fractional = ft_strjoin(ft_strspace(19 - max, 2), fractional);
	fractional = ft_fractional_roungding(fractional);
	accur_frac= ft_strnew(flag->accuracy + 1);
	accur_frac = ft_strncpy(accur_frac, fractional, flag->accuracy + 1);
	fractional = ft_fractional_roungding(accur_frac);
	accur_frac = ft_strnew(flag->accuracy);
	accur_frac = ft_strncpy(accur_frac, fractional, flag->accuracy);
	return (accur_frac);
}

char	*ft_flot_str(long double u, t_flag *flag)
{
	char	*p;
	char	*integer;
	char	*fractional;
	long long int point;
	int len;

	point = 0;
//todo	if(u == целое число,   u - (int)u *10 в максимальной степени)
	integer = ft_integer_number(u, flag);
	fractional = ft_fractional_number(u, flag, integer);
	len = ft_strlen (fractional);
	if (flag->accuracy > len)
	{
		p = ft_strjoin(fractional, ft_strspace(flag->accuracy - len, 2));
		free(fractional);
		fractional = p;
	}
	p = ft_strjoin(integer, fractional);
	return (p);
}

long double	ft_flot_flag_l(t_flag *flag, va_list str, int n)
{
	int p;

	p = 0;
	if (flag->specif == 'X')
		p = 1;
	if(flag->l)
		return ((long)va_arg(str, long), n, p);
	if(flag->ll)
		return((long long int)va_arg(str, long long), n, p);
	if(flag->h)
		return(va_arg(str, int), n, p);
	if(flag->hh)
		return(va_arg(str, int), n, p);
	return (0);
}

void	func_f(size_t i, const char *fr, va_list str)
{
	long double u;
	t_flag	*flag;
	char	*p;
	int		len;
	int		z;

	z = 0;
	flag = ft_flag(fr, i, 'f');
	if (flag->accuracy == -1)
		flag->accuracy = 6;
	if(flag->l || flag->ll || flag->h || flag->hh)
		u = ft_flot_flag_l(flag, str, 10);
	else
		u = (long double)va_arg(str, double);
	if (u < 0)
	{
		flag->str_min = 1;
		u = u * -1;
	}
	p = ft_flot_str(u, flag);
	len = ft_strlen(p);
	if (flag->plus || flag->str_min)
		z = 1;
	if(flag->space)
		ft_flag_spase(len, z, flag, p);
	if(flag->min)//todo || flag->accuracy > -1)
		flag->zero = 0;
//	if (p[0] == '0' && (flag->accuracy == 0))
//	{
//		p[0] = 0;
//		len--;
//	}
	if (flag->min == 0)
		ft_di_right(len, z, flag, p);
	if (flag->min == 1)
		ft_di_left(len, z, flag, p);
	if (flag->min == 0)
		ft_strlistadd_end(&g_str, newnode(p));
	free(flag);
}