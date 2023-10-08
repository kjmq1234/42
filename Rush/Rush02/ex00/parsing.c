/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:18:45 by heerpark          #+#    #+#             */
/*   Updated: 2023/08/06 18:06:53 by heerpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long long	dict_size(char *path)
{
	long long	file;
	char		buff[1];
	long long	count;

	count = 0;
	file = open(path, O_RDONLY);
	if (file < 0)
		return (-1);
	while (read(file, buff, 1) > 0)
	{
		count++;
	}
	close(file);
	return (count);
}

char	*dict_to_str(char *path, long long len)
{
	char		*dict;
	long long	file;

	dict = (char *)malloc(sizeof(char) * len + 1);
	if (!dict)
		return (0);
	file = open(path, O_RDONLY);
	if (file < 0)
		return (0);
	read(file, dict, len);
	dict[len] = '\0';
	close(file);
	return (dict);
}

long long	parsing(char *dict, t_dict *s_head)
{
	long long	idx;
	char		arr[5000];

	idx = 0;
	array_reset(arr, 5000);
	while (*dict)
	{
		arr[idx] = *dict;
		if (*dict == '\n' || *(dict + 1) == '\0')
		{
			if (dict_rule(arr))
				to_struct(my_atoi(arr), str_to_value(arr), s_head);
			else
				return (0);
			array_reset(arr, idx + 1);
			idx = 0;
		}
		else
			idx++;
		dict++;
	}
	return (1);
}
