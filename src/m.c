#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("my printf - |%0.d|\n", -1);
	printf("origin - |%0.d|\n", -1);
	ft_printf("my printf - |%0.d|\n", 0);
	printf("origin - |%0.d|\n", 0);
	ft_printf("my printf - |%0.d|\n", 12);
	printf("origin - |%0.d|\n", 12);
	printf("||\n");
}