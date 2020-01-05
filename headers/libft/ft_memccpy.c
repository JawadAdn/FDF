/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:59:53 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/09 14:25:26 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*p1;
	unsigned const char	*p2;
	size_t				i;

	i = 0;
	p1 = dst;
	p2 = src;
	while (i < n)
	{
		if (p2[i] == (unsigned char)c)
		{
			p1[i] = (unsigned char)c;
			return (&dst[i + 1]);
		}
		p1[i] = p2[i];
		i++;
	}
	return (NULL);
}
