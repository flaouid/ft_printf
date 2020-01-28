/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:17:24 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/13 16:58:11 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy_word(const char *src, char limit)
{
	int			i;
	char		*output;

	i = 0;
	while (src[i] && src[i] != limit)
		i++;
	output = (char*)malloc(i);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != limit)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

static int		count_words(const char *str, char limit)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != limit)
		{
			count++;
			while (str[i] && str[i] != limit)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

static char		**free_tab(char **tab, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char		**dest;
	int			i;
	int			x;

	if (s == 0 || !(dest = (char**)malloc(sizeof(char*) * count_words(s, c))))
		return (NULL);
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if ((dest[x] = copy_word(s + i, c)) == NULL)
				return (free_tab(dest, x));
			while (s[i] && s[i] != c)
				i++;
			x++;
		}
		else
			i++;
	}
	dest[x] = 0;
	return (dest);
}
