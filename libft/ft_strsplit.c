/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:48:57 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_b(char const *str, int *i, char c)
{
	int		z;
	int		k;
	char	*b;

	k = *i;
	while (str[k] == c)
		k++;
	z = 0;
	while (str[k + z] != c && str[k + z] != '\0')
	{
		z++;
	}
	b = (char *)malloc(sizeof(char) * (z + 1));
	if (!b)
		return (NULL);
	z = 0;
	while (str[k] != c && str[k] != '\0')
	{
		b[z++] = str[k++];
	}
	b[z] = '\0';
	*i = k;
	return (b);
}

static char	**ft_free(char **d, int i)
{
	i--;
	while (i >= 0)
		free(d[i--]);
	free(d);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	int		j;
	char	**new;

	if (!s)
		return (NULL);
	j = 0;
	n = ft_word(s, c);
	new = (char **)malloc(sizeof(char*) * (n + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && j < n)
	{
		new[j] = ft_b(s, &i, c);
		if (!new[j])
			return (ft_free(new, j));
		j++;
	}
	new[j] = NULL;
	return (new);
}
