/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:56:36 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/09 16:55:45 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const char		*p1;
	const char		*p2;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (i < n && *p1 == *p2)
	{
		p1++;
		p2++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*p1 - (unsigned char)*p2);
}
