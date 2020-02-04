/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:17:43 by ablane            #+#    #+#             */
/*   Updated: 2020/01/22 17:50:20 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		s;
	int		b;
	char	*str;

	str = (char*)haystack;
	s = 0;
	if (needle[s] == '\0')
		return (&str[s]);
	while (str[s] != '\0')
	{
		b = 0;
		while (needle[b] == str[s + b])
		{
			if (needle[b + 1] == '\0')
				return (&str[s]);
			b++;
		}
		s++;
	}
	return (0);
}
