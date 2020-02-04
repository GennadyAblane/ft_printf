/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:07 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	p;
	size_t	n;
	size_t	m;

	i = ft_strlen(dst);
	p = ft_strlen(src);
	n = i;
	m = 0;
	if (size == 0)
		return (p);
	while (n < (size - 1) && src[m])
		dst[n++] = src[m++];
	dst[n] = '\0';
	if (size > i)
		return (i + p);
	else
		return (size + p);
	return (0);
}
