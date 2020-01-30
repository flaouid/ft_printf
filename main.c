#include <stdio.h>
#include "./include/printf.h"

int main(void)
{
	int number=5;
	char *pointer = "little";

	ft_printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);
	printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);
}
