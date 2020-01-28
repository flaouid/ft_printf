#include "printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			ret;

	va_start(args, str);
	ret = ft_printf(1, str, args);
	va_end(args);
	return (ret);
}
