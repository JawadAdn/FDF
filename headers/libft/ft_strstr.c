/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:16:48 by mel-adna          #+#    #+#             */
/*   Updated: 2019/03/30 16:52:09 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int stop;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			stop = 0;
			i = 0;
			while (needle[i] && stop == 0)
			{
				if (needle[i] != haystack[i])
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
