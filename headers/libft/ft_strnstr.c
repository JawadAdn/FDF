/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:53:13 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/02 16:28:16 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int stop;
	int len2;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len--)
	{
		if (*haystack == *needle)
		{
			stop = 0;
			i = 0;
			len2 = len + 1;
			while (needle[i] && stop == 0)
			{
				if (needle[i] != haystack[i] || !len2--)
					stop = 1;
				i++;
			}
			if (stop == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
