/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:49:42 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*z;
	unsigned char	*x;
	size_t			i;

	i = 0;
	z = (unsigned char*)dst;
	x = (unsigned char*)src;
	while (z || x)
	{
		if (z > x)
		{
			while (len-- > 0)
				z[len] = x[len];
		}
		else
		{
			while (i < len)
			{
				z[i] = x[i];
				i++;
			}
		}
		return (z);
	}
	return (NULL);
}
