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

char** copy_map(char** map, t_map info)
{
	unsigned long long	i;
	char**				copy;

	i = 0;
	copy = (char**) malloc(sizeof(char*) * info.height);
	if(!copy)
		exit(1);
	while (i < info.height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

void free_maps(char** map, t_map info)
{
	unsigned long long i;

	i = 0;
	while (i < info.height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}