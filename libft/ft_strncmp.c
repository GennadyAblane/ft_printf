/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:39:53 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	a = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[a] == (unsigned char)s2[a] && a < n - 1)
	{
		if (s1[a] == '\0' || s2[a] == '\0')
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
