#include "so_long.h"

size_t	ft_strlen_n(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		if (*s == '\n')
			len--;
		s++;
	}
	return (len);
}

void exit_open(void)
{
	printf("잘못된 파일명입니다.");
	exit(1);
}