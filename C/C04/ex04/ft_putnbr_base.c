/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:07:48 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/27 17:29:39 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(int base_num, char *base, int i, int j)
{
	if ((base_num == 0) || (base_num == 1))
		return (-1);
	while (base[i])
	{
		if ((base[i] == '+') || (base[i] == '-'))
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

void	ft_putnbr(long long nbr, int base_num, char *base)
{
	char	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	n = base[nbr % base_num];
	if (nbr / base_num != 0)
		ft_putnbr(nbr / base_num, base_num, base);
	write(1, &n, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	lnbr;
	int			base_num;

	lnbr = nbr;
	base_num = ft_strlen(base);
	if (check_base(base_num, base, 0, 0) == -1)
		return ;
	ft_putnbr(lnbr, base_num, base);
}
