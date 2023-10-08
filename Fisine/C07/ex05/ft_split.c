/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:46:04 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/06 16:42:48 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	charset_invalid(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	str_count(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && charset_invalid(*str, charset))
			str++;
		if (!charset_invalid(*str, charset))
			i++;
		while (*str && (!charset_invalid(*str, charset)))
			str++;
	}
	return (i);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str && !charset_invalid(*str, charset))
	{
		str++;
		i++;
	}
	return (i + 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	arr = (char **) malloc(sizeof(char *) * (str_count(str, charset) + 1));
	while (*str)
	{
		j = 0;
		if (*str && (!charset_invalid(*str, charset)))
		{
			arr[i] = (char *)malloc(sizeof(char) * (ft_strlen(str, charset)));
			while (*str && (!charset_invalid(*str, charset)))
				arr[i][j++] = *str++;
			arr[i][j] = '\0';
			i++;
		}
		else
			str++;
	}
	arr[i] = NULL;
	return (arr);
}
