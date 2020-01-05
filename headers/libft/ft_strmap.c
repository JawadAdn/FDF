/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:50:32 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/09 14:29:50 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*ptr;
	int		i;

	if (!s || !f)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		ptr[i] = (*f)(*s);
		s++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
