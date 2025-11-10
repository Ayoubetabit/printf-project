#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int f = ft_printf("%%%y");
	printf("\n");
	int d = printf("%%%y");
	printf("\n");
	printf("m printf%d\ns printf%d\n", f, d);
}
