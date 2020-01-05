/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:28:48 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/11 01:13:47 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*buf;

	if ((size_t)(dst - src) >= len)
		ft_memcpy(dst, src, len);
	else
	{
		buf = malloc(len);
		if (!buf)
			return (NULL);
		ft_memcpy(buf, src, len);
		ft_memcpy(dst, buf, len);
		free(buf);
	}
	return (dst);
}
