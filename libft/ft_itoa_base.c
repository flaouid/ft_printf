#include "libft.h"

static void	rec_itoa_ll(unsigned long long int value, char *base,
char **str, int size)
{
	if (value / ft_strlen(base) == 0)
	{
		*str = (char*)malloc(sizeof(char) * size + 1);
		(*str)[size] = '\0';
		(*str)[size - 1] = base[value % ft_strlen(base)];
	}
	else
	{
		rec_itoa_ll(value / ft_strlen(base), base, str, size + 1);
		(*str)[size - 1] = base[value % ft_strlen(base)];
	}
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	if (str[i] == '-')
		i++;
	while (i < --len)
	{
		tmp = str[len];
		str[len] = str[i];
		str[i++] = tmp;
	}
	return (str);
}

char		*ft_unsigned_itoa_base(unsigned long long int value, char *base)
{
	char *str;

	rec_itoa_ll(value, base, &str, 1);
	return (ft_strrev(str));
}
