/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:00:01 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/09 14:47:05 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int start;
	unsigned int end;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return ((char *)s);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && (s[start] == ' ' || s[start] == '\n' ||
				s[start] == '\t'))
		start++;
	while (end > start && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	return (ft_strsub(s, start, (size_t)(end - start + 1)));
}
