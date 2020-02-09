#include <stdio.h>
#include "./include/printf.h"

int main(void)
{
	ft_printf("%10.5d\n", -216);
	printf("%10.5d\n", -216);
	ft_printf("%8.3i\n", -8473);
	printf("%8.3i\n", -8473);
	ft_printf("%5p\n", NULL);
	printf("%5p\n", NULL);
	ft_printf("%7i\n", -14);
	printf("%7i\n", -14);

}
