#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"
#include <unistd.h>
#include "ft_printf.h"
int main(void)
{
    int a;
    //write(1, "%", 1);
    ft_printf("%d\n", ft_printf("%p\n", &a));
    printf("%d\n", printf("%p\n", &a));
    //ft_putptr_fd(&a, 1);
}
