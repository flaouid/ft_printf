/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:15:30 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/03 13:23:04 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

void			strjoin_free(char *add, char **src, int type)
{
	char		*dest;

	if (!add || !src)
		return ;
	dest = (char*)malloc(ft_strlen(add) + ft_strlen(*src) + 1);
	if (!dest)
		return ;
	if (type == JOIN_START)
	{
		ft_strcpy(dest, add);
		ft_strcat(dest, *src);
	}
	if (type == JOIN_END)
	{
		ft_strcpy(dest, *src);
		ft_strcat(dest, add);
	}
	if (type == JOIN_START || type == JOIN_END)
	{
		free(*src);
		*src = dest;
	}
	free(dest);
	free(*src);
}

void			add_str(char **str, char type, int number, int start)
{
	char		*dest;
	char		*tmp;

	tmp = (char*)malloc(sizeof(char) * (number + 1));
	if (!tmp)
		return ;
	ft_memset(tmp, type, number);
	tmp[number] = '\0';
	if (!start)
		dest = ft_strjoin(*str, tmp);
	else
	{
		if (*str && (*str)[0] == '-' && type == '0')
		{
			tmp[0] = (*str)[0];
			(*str)[0] = '0';
		}
		dest = ft_strjoin(tmp, *str);
	}
	free(*str);
	free(tmp);
	*str = dest;
}
