/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:02:41 by jaemikim          #+#    #+#             */
/*   Updated: 2024/01/31 22:56:59 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
	static char	*data_table[OPEN_MAX + 1];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (data_table[fd] == NULL)
		data_table[fd] = ft_strdup("");
	line = get_line(fd, buffer, data_table[fd]);
	free(buffer);
	return (line);
}

char	*get_line(int fd, char* buffer, char* backup)
{
	int return_val;
	return_val = read_line(fd, buffer, backup);
	if (return_val == -1)
	{
		free(backup);
		return (NULL);
	}
	if (ft_strchr(backup, '\n'))
		return (separate_line(&backup));
	return (backup);
}

int	read_line(int fd, char* buffer, char* backup)
{
	int		bytes;
	char	*newbackup;
	
	bytes = 1;
	while (!(ft_strchr(backup, '\n')) && (bytes != 0))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (bytes);
		newbackup = backup;
		backup = ft_strjoin(newbackup, buffer);
		free(newbackup);
	}
	return (bytes);
}

static char	*separate_line(char **backup)
{
	int		idx; // \n의 위치를 찾기 위한 인덱스
	char	*line; // \n 전까지 문자열
	char	*old_backup; // line을 구하기 위한 변수

	idx = 0;
	while ((*backup)[idx] != '\n')
		idx++;
	old_backup = *backup;
	// \n의 그 전부분 저장
	line = ft_substr(old_backup, 0, idx + 1);
	// \n을 만난 그 뒷부분을 저장
	*backup = ft_strdup(&(*backup)[idx + 1]);
	free(old_backup);
	return (line);
}