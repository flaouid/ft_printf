/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:55:56 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/18 15:18:19 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (lst)
	{
		if (!(new_list = (t_list*)malloc(sizeof(lst))))
			return (NULL);
		new_list = f(lst);
		new_list->next = ft_lstmap(lst->next, f, del);
		return (new_list);
	}
	return (NULL);
}
