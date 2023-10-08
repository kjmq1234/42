/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:08:45 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/02 23:22:26 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_count(char **strs, int size)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < size)
	{
		cnt += ft_strlen(strs[i]);
		i++;
	}
	return (cnt);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		scnt;
	int		i;
	int		slen;

	slen = total_count(&*strs, size);
	scnt = ft_strlen(sep);
	i = 0;
	if (size == 0)
		arr = (char *) malloc(1);
	else
		arr = (char *) malloc(sizeof(char) * (slen + 1 + scnt * (size - 1)));
	if (!arr)
		return (0);
	arr[0] = '\0';
	while ((i < size) && (strs[i]))
	{
		ft_strcat(arr, strs[i]);
		if (i < size - 1)
			ft_strcat(arr, sep);
		i++;
	}
	return (arr);
}
