#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "ft_printf.h"
int main(void)
{
    //write(1, "%", 1);
    printf("%d\n", ft_printf(" %s ", ""));
    //print(" % s ", "");
    //printf("%d\n", printf("% s\n", ""));
    //printf("%d", ft_putptr_fd(NULL, 1));
}
