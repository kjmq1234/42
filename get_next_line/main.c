#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line.c"
#include <fcntl.h>
#include "get_next_line_utils.c"
int main(void)
{
   int fd = open("test.txt", O_RDONLY);
   printf("%s", get_next_line(fd));

//    printf("%s", ft_strchr("adas\0asd", '\0'));
}