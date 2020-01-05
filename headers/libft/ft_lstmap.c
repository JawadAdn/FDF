/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:40:02 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/16 14:36:56 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ma_list;
	t_list *elem;

	if (!lst || !f)
		return (NULL);
	ma_list = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size);
	lst = lst->next;
	while (lst)
	{
		elem = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size);
		ft_lstaddend(ma_list, elem);
		lst = lst->next;
	}
	return (ma_list);
}
