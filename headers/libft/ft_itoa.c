/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:18:49 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/13 13:52:43 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_check_num_size(int n, unsigned int *num)
{
	long	size;
	long	i;

	if (n == 0)
	{
		*num = 0;
		return (1);
	}
	*num = n;
	size = 0;
	if (n < 0)
	{
		size = 1;
		*num = -n;
	}
	i = *num;
	while (i > 0)
	{
		size++;
		i /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	unsigned int	num;
	long			size;
	char			*rep;

	size = ft_check_num_size(n, &num);
	rep = (char *)ft_memalloc((size + 1) * sizeof(char));
	if (!rep)
		return (NULL);
	while (size > 0)
	{
		rep[size - 1] = num % 10 + '0';
		size--;
		num /= 10;
	}
	if (n < 0)
		rep[0] = '-';
	return (rep);
}
