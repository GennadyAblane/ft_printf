/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:18:58 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*new;
	size_t		m;
	size_t		l;
	size_t		i;
	size_t		b;

	if (!s)
		return (NULL);
	m = ft_strlen(s) - 1;
	l = 0;
	i = 0;
	while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
		l++;
	while ((s[m] == ' ' || s[m] == '\n' || s[m] == '\t') && (l < m))
		m--;
	new = (char *)malloc(sizeof(char) * (m - l + 2));
	if (!new)
		return (NULL);
	b = l;
	while (m + 1 > l)
		new[i++] = s[l++];
	if (i == (m - b + 1))
		new[i] = '\0';
	return (new);
}
