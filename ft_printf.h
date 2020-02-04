/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:21:05 by ablane            #+#    #+#             */
/*   Updated: 2020/02/04 09:32:24 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

# define ALL_SPEC {'c', 's', 'p', 'd', 'i', 'o', 'u', \
'x', 'X', 'f', 'e', 'g', 'b', 'r', 'k', '%', '\0'}

typedef struct		s_str
{
	char			*string;
	size_t			counchar;
	struct s_str	*next;

}					t_str;

t_str *g_str;

typedef struct		s_flag
{
	ssize_t			wild;
	ssize_t			accuracy;
	ssize_t			min;
	ssize_t			plus;
	ssize_t			zero;
	ssize_t 		reshotka;
	ssize_t 		space;
	ssize_t 		l;
	ssize_t 		L;
	ssize_t 		h;
	ssize_t 		ll;
	ssize_t 		hh;
	ssize_t 		str_min;
	char 			specif;
	struct s_flag	*next;

}					t_flag;

int		ft_printf(const char *fr, ...);
int 	print_string(void);
int		count(t_str *tmp, size_t n);
int		ft_correct_input_for_c(const char *fr, size_t i);
int		ft_intlenpf(unsigned long long int a, unsigned long long int m);
void	ft_add_width(size_t i, size_t o);
void 	percent(int i, const char *fr, va_list str);
void	ft_strlistadd_end(t_str **alst, t_str *new);
void	ft_strlistadd_penultimate(t_str **alst, t_str *new);
void 	func_di(size_t p, const char *fr, va_list str);
char	*ft_line_numbers(char *in, char c);
char	*ft_strspace(size_t size, size_t z);
char	*ft_octothorpe(char *d, ssize_t len);
char	*ft_signed_int(t_flag *flag, va_list str, int n);
char	*ft_itoa_base(long long int n, int base, int l_size);
char	*ft_to_mat(unsigned long long int a, int i, unsigned long long int m);
void	func_c(size_t i, const char *fr, va_list str);
void	func_s(size_t i, const char *fr, va_list str);
void	func_p(size_t i, const char *fr, va_list str);
void	func_o(size_t i, const char *fr, va_list str);
void	func_u(size_t i, const char *fr, va_list str);
void	func_x(size_t i, const char *fr, va_list str);
void	func_percent(size_t i, const char *fr, va_list str);
void	ft_flag_spase(ssize_t len, ssize_t z, t_flag *flag, char *p);
void	ft_max_accuracy(ssize_t len, ssize_t z, t_flag *flag, char *p);
void	ft_no_ac_and_wild(ssize_t len, ssize_t z, t_flag *flag, char *p);
t_str 	*newnode(char *c);
t_flag	*ft_flag(const char *c, size_t i, char spec);
size_t	ret_int(const char *fr, size_t i);
size_t	ret_size_t(const char *fr, size_t i);
size_t	between(const char *fr, size_t i);
size_t	ft_point_p(const char *fr, size_t p, size_t i, char c);
size_t	ft_flag_mi_zer(const char *fr, size_t i);
size_t	between_to_spase(const char *fr, size_t i);
ssize_t ft_find_l(const char *fr, size_t i, char spec);
ssize_t ft_find_L(const char *fr, size_t i, char spec);
ssize_t ft_find_h(const char *fr, size_t i, char spec);
ssize_t ft_find_ll(const char *fr, size_t i, char spec);
ssize_t ft_find_hh(const char *fr, size_t i, char spec);
ssize_t ft_find_min(const char *fr, size_t i, char spec);
ssize_t ft_find_plus(const char *fr, size_t i, char spec);
ssize_t ft_find_zero(const char *fr, size_t i, char spec);
ssize_t ft_find_wild(const char *fr, size_t i, char spec);
ssize_t ft_find_space(const char *fr, size_t i, char spec);
ssize_t ft_find_accuracy(const char *fr, size_t i, char spec);
ssize_t ft_find_reshotka(const char *fr, size_t i, char spec);
char	*ft_whild_percision(char *c, const char *fr, size_t i, char spec);



void ft_max_wild(ssize_t len, ssize_t z, t_flag *flag, char *p);



#endif