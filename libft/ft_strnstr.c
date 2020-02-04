/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:40:11 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		s;
	int		b;
	char	*str;

	str = (char*)haystack;
	s = 0;
	b = 0;
	if (needle[s] == '\0')
		return (&str[s]);
	while (str[s] != '\0' && (s < (int)len))
	{
		b = 0;
		while (needle[b] == str[s + b] && (s + b) <= (int)len)
		{
			if (needle[b + 1] == '\0')
			{
				return (&str[s]);
			}
			b++;
		}
		s++;
	}
	return (0);
}
