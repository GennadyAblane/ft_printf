/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 10:05:11 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char 	*m;
	size_t	i;

	i = 0;
	m = (char *)malloc(sizeof(char) * (n + 1));
	if (m == NULL)
		return (NULL);
	while (i < n)
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
