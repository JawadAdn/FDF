/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:28:11 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/04 11:51:29 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*rep;
	char		*hlp;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	rep = (char *)malloc(len * sizeof(char));
	if (rep == NULL)
		return (NULL);
	hlp = rep;
	while ((*rep++ = *s1++))
		;
	rep--;
	while ((*rep++ = *s2++))
		;
	return (hlp);
}
