/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:58:03 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/21 16:59:44 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst && *lst)
	{
		tmp1 = *lst;
		while (tmp1)
		{
			tmp2 = tmp1->next;
			del(tmp1->content);
			free(tmp1);
			tmp1 = tmp2;
		}
		*lst = (NULL);
	}
}
