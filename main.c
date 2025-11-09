#include "ft_printf.h"

int     main()
{
    printf("CHAR:\n");
    ft_printf("ft: %c\n", 'A');
    printf("og: %c\n", 'A');

    printf("STRING:\n");
    ft_printf("ft: %s%s\n", "Hello, world!", NULL);
    printf("og: %s%s\n", "Hello, world!", NULL);

    printf("POINTER:\n");
    ft_printf("ft: %p\n", (void *)0);
    printf("og: %p\n", (void *)0);
    ft_printf("ft: %p %p %p\n", (void *)0x1234abcd, NULL);
    printf("og: %p %p %p\n", (void *)0x1234abcd, NULL);

    printf("DECIMAL:\n");
    ft_printf("ft: %d %d %d\n", 0, -42 , NULL);
    printf("og: %d %d %d\n", 0, -42, NULL);

    printf("INTEGER:\n");
    ft_printf("ft: %i %i %i\n", 42, -2147483648, NULL);
    printf("og: %i %i %i\n", 42, -2147483648, NULL);

    printf("UNSIGNED:\n");
    ft_printf("ft: %u %u %u\n", 0, 4294967295,NULL);
    printf("og: %u %u %u\n", 0, 4294967295,NULL);

    printf("HEXA (lower):\n");
    ft_printf("ft: %x %x %x\n", 255, 0, NULL);
    printf("og: %x %x %x\n", 255, 0, NULL);

    printf("HEXA (upper):\n");
    ft_printf("ft: %X %X %X\n", 255, 0, NULL);
    printf("og: %X %X %X\n", 255, 0, NULL);

    printf("PERCENT:\n");
    ft_printf("ft: %%\n");
    printf("og: %%\n");

}