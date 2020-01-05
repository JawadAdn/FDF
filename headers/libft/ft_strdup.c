/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:34:49 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/09 16:58:29 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cp;
	int		i;

	s1_cp = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s1_cp == NULL)
		return (NULL);
	i = 0;
	while ((s1_cp[i++] = *s1++))
		;
	return (s1_cp);
}
