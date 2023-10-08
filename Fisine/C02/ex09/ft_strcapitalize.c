/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:45:04 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/30 20:10:47 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase_1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}

int	change_low(char *str, int i)
{
	if (i == 0)
	{
		*str -= 'a' - 'A';
		i = 1;
	}
	return (i);
}

int	check_flag(char *str, int i)
{
	if ((*str >= 'a') && (*str <= 'z'))
	{
		i = change_low(str, i);
	}
	else if ((*str >= '0') && (*str <= '9'))
	{
		if (i == 0)
			i = 1;
	}
	else if ((*str >= 'A') && (*str <= 'Z'))
	{
		if (i == 0)
			i = 1;
	}
	else
	{
		if (i == 1)
			i = 0;
	}
	str++;
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = str;
	ft_strlowcase_1(str);
	while (*str)
	{
		i = check_flag(str, i);
		str++;
	}
	*str = '\0';
	return (ptr);
}
