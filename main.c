#include <stdio.h>
#include "./include/printf.h"

int main(void)
{
	int i;

	ft_printf("_%x_\n", 0);
	printf("_%x_\n", 0);
	ft_printf("_%.0x_\n", 0);
	printf("_%.0x_\n", 0);
	ft_printf("_%.x_\n", 0);
	printf("_%.x_\n", 0);
	ft_printf("%-*.*s\n", -7, -3, "yolo");
	printf("%-*.*s\n", -7, -3, "yolo");
	ft_printf("%s\n", "yolo");
	printf("%s\n", "yolo");
	ft_printf("%15.p\n", &i);
	printf("%15.p\n", &i);
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%x\n", 0);
	printf("%x\n", 0);
	ft_printf("%x\n", -1);
	printf("%x\n", -1);
	ft_printf("%.2x\n", 1);
	printf("%.2x\n", 1);
	ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	printf("@moulitest: %.x %.0x\n", 0, 0);
	ft_printf("this is a %s\n", "string");
	printf("this is a %s\n", "string");
	ft_printf("%d\n", -1);
	printf("%d\n", -1);
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	system("leaks a.out");
}
