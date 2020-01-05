/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:02:31 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/05 01:30:56 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**str;
	int		len;
	if (!s)
		return (NULL);
	i = 0;
	len = ft_count_words((char *)s, c) + 1;
	if (!(str = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end > start)
			*str++ = ft_strsub(s, start, end - start);
	}
	*str = 0;
	return (str - (len - 1));
}
