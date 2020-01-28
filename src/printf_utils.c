#include "../include/printf.h"

void	strjoin_free(char *add, char **src, int type)
{
	char *dest;

	if (!add || !src)
		return ;
	dest = (char*)malloc(ft_strlen(add) + ft_strlen(*src) + 1);
	if (!dest)
		return ;
	if (type == JOIN_START)
	{
		ft_strcpy(dest, to_add);
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
}

// Fonction qui ajoute les 0 ou " " a une chaine.

void	add_str(char **str, char type, int number, int start)
{
	char *dest;
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * (number + 1));
	if (!tmp)
		return ;
	ft_memset(tmp, type, number);
	tmp[number] = '\0';
	if (!dest)
		dest = ft_strjoin(*str, tmp);
	else
	{
		if (((*str)[0] == '-' || (*str)[0] == '+' || (*str)[0] == ' ') && type == '0')
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
