#include "libft.h"

void	ft_strdel(char *str)
{
	int i;
	int j;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
			;
	j = -1;
	while (++j < i)
		str[j] = '\0';
}
