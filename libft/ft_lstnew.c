/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:16:48 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/18 15:13:16 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new_element;

	if (!(new_element = malloc(sizeof(t_list))))
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
