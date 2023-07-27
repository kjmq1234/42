/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:36:39 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/27 17:47:52 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_active(char str, char *base);

int	check_base(int base_num, char *base, int i, int j)
{
	if ((base_num == 0) || (base_num == 1))
		return (-1);
	while (base[i])
	{
		if ((base[i] == '+') || (base[i] == '-') || (base[i] == 32))
			return (-1);
		else if ((base[i] >= 9) && (base[i] <= 13))
			return (-1);
		i++;
	}
		i = 0;
	while (i + 1 < base_num)
	{
		j = i + 1;
		while (j < base_num)
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, char *base, long long to_int, int sign)
{
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	while (*str)
	{
		if (check_active(*str, base) != -1)
			to_int = to_int * ft_strlen(base) + check_active(*str, base);
		else if (((*str == '+') || (*str == '-')) && (to_int == 0))
		{
			if (*str == '-')
				sign *= -1;
		}
		else
			break ;
		str++;
	}
	if (to_int == -1)
		return (0);
	else
		return (sign * (int) to_int);
}

int	check_active(char str, char *base)
{
	int	i;

	i = 0;
	while (i < ft_strlen(base))
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_num;

	base_num = ft_strlen(base);
	if (check_base(base_num, base, 0, 0) == -1)
		return (0);
	return (ft_atoi(str, base, 0, 1));
}
