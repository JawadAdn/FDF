/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:50:14 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/13 19:26:05 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *lst, t_list *new)
{
	if (lst && new)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
		new->next = NULL;
	}
}
