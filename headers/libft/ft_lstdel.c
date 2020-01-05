/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:11:31 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/13 14:36:46 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			p = *alst;
			*alst = (*alst)->next;
			(*del)(p->content, p->content_size);
			free(p);
		}
		p = NULL;
		*alst = NULL;
	}
}
