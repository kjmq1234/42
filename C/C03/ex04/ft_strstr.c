/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:20:21 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/25 15:00:14 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp_2(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i != n) && ((*s1 != '\0') || (*s2 != '\0')))
	{
		if (*s1 > *s2)
			return (1);
		else if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

int	ft_strlen_2(char *dest)
{
	int	i;

	i = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			if (ft_strncmp_2(str, to_find, ft_strlen_2(to_find)) == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
