/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:21:03 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	b;
	char	*map;

	b = 0;
	i = 0;
	if (s && f)
	{
		b = ft_strlen(s);
		map = (char *)malloc(sizeof(char) * (b + 1));
		if (!map)
			return (NULL);
		while (i < b)
		{
			map[i] = f(s[i]);
			i++;
		}
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
