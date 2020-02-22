#include "libft.h"

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*output;

	if (!(output = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	//if (n == 2147483648)
	//	return (output = ft_strdup("-2147483648"));
	if (n < 0)
	{
		output[0] = '-';
		output[1] = '\0';
		output = ft_strjoin(output, ft_itoa_unsigned(-n));
	}
	else if (n >= 10)
		output = ft_strjoin(ft_itoa_unsigned(n / 10), ft_itoa_unsigned(n % 10));
	else if (n < 10 && n >= 0)
	{
		output[0] = n + '0';
		output[1] = '\0';
	}
	return (output);
}
