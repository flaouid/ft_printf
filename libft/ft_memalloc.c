/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:07:15 by flaouid           #+#    #+#             */
/*   Updated: 2020/02/24 16:47:46 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = (char*)malloc(sizeof(size_t) * size);
	if (ptr)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	free(ptr);
	return (NULL);
}
