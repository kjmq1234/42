/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:14:09 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/06 20:25:37 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *c)
{
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{	
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
