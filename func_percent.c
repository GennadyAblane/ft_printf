/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:23:20 by ablane            #+#    #+#             */
/*   Updated: 2020/02/06 10:43:00 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	func_percent(size_t i, const char *fr)
{
	t_flag *flag;

	flag = ft_flag(fr, i, '%');

	if (flag->min)
	{
		flag->zero = 0;
		ft_strlistadd_end(&g_str, newnode("%"));
	}
	if (flag->wild > 1)
		ft_strlistadd_end(&g_str, newnode(ft_strspace(flag->wild - 1,
													  flag->zero)));
	if (flag->min == 0)
		ft_strlistadd_end(&g_str, newnode("%"));
	free(flag);
}