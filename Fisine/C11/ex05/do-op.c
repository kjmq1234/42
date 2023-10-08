/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:51:33 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/09 23:07:45 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

void	ft_putnbr(long long nb)
{
	char	n;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	n = nb % 10 + 48;
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	write(1, &n, 1);
}

int	ft_atoi(char *str)
{
	long long int	to_int;
	int				sign;

	to_int = 0;
	sign = 1;
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
		{
			to_int = to_int * 10 + (*str - 48);
		}
		else if (((*str == '+') || (*str == '-')) && (to_int == 0))
		{
			if (*str == '-')
				sign *= -1;
		}
		else
			break ;
		str++;
	}
	return ((int) sign * to_int);
}

void	print(int num1, int num2, char *oper)
{
	int			i;
	long long	(*operater[5])(int, int);

	operater[0] = plus;
	operater[1] = minus;
	operater[2] = multiple;
	operater[3] = division;
	operater[4] = modulo;
	i = operator(num2, oper);
	if (i == -1)
		return ;
	i = (*operater[i])(num1, num2);
	ft_putnbr(i);
}

int	operator(int num2, char *oper)
{
	if (!ft_strcmp(oper, "+"))
		return (0);
	else if (!ft_strcmp(oper, "-"))
		return (1);
	else if (!ft_strcmp(oper, "*"))
		return (2);
	else if (!ft_strcmp(oper, "%"))
	{
		if (num2 == 0)
		{
			write(1, "Stop : modulo by zero", 21);
		}
		else
			return (4);
	}
	else if (!ft_strcmp(oper, "/"))
	{
		if (num2 == 0)
			write(1, "Stop : division by zero", 23);
		else
			return (3);
	}
	else
		write(1, "0", 1);
	return (-1);
}

int	main(int argc, char *argv[])
{
	int			num1;
	int			num2;

	num1 = 0;
	num2 = 0;
	if (argc != 4)
		return (0);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	print(num1, num2, argv[2]);
	write(1, "\n", 1);
}
