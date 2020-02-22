#include <stdio.h>
#include "./include/printf.h"

int main(void)
{
//	int i;
	ft_printf("_%x_\n", 0);
	printf("_%x_\n", 0);
	ft_printf("_%.0x_\n", 0);
	printf("_%.0x_\n", 0);
	ft_printf("_%.x_\n", 0);
	printf("_%.x_\n", 0);
	ft_printf("%-*.*s\n", -7, -3, "yolo");
	printf("%-*.*s\n", -7, -3, "yolo");
	ft_printf("%-*.*s\n", -7, 3, "yolo");
	printf("%-*.*s\n", -7, 3, "yolo");
//	ft_printf("%15.p\n", &i);
//	printf("%15.p\n", &i);


}
