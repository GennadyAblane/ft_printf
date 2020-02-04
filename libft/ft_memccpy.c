/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:13:03 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*z;
	unsigned char	*x;
	size_t			i;

	i = 0;
	z = (unsigned char*)destination;
	x = (unsigned char*)source;
	while (i < n)
	{
		z[i] = x[i];
		if (x[i] == (unsigned char)c)
			return (&z[i + 1]);
		i++;
	}
	return (NULL);
}
