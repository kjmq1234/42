/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:41:46 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/30 02:52:30 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	int	sum;
	int	flag;

	sum = 0;
	flag = 1;
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		sum = sum * 10 + (*str - 48);
		str++;
	}
	return (flag * sum);
}
