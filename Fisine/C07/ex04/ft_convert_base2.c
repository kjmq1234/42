/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:28:17 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/03 13:55:14 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_base(int base_num, char *base, int i, int j);
int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);

void	ft_rev(char *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i != size / 2)
	{
		temp = tab[size - i - 1];
		tab[size - i -1] = tab[i];
		tab[i] = temp;
		i++;
	}
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i != n)
	{
		*dest = *src;
		dest++;
		if (*src != '\0')
			src++;
		i++;
	}
	*dest = '\0';
	return (dest);
}

int	ft_putnbr(long long nbr, int base_num, char *base, char *arr)
{
	int	size;
	int	flag;

	flag = 0;
	size = 0;
	if (nbr < 0)
	{
		flag = -1;
		nbr *= -1;
	}
	while (nbr / base_num != 0)
	{
		arr[size++] = base[nbr % base_num];
		nbr /= base_num;
	}
	arr[size++] = base[nbr % base_num];
	if (flag == -1)
		arr[size++] = '-';
	return (size);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	lnbr;
	int			base_num;
	char		arr[64];
	int			size;
	char		*real;

	lnbr = nbr;
	base_num = ft_strlen(base);
	if (check_base(base_num, base, 0, 0) == -1)
		return (NULL);
	size = ft_putnbr(lnbr, base_num, base, arr);
	real = (char *) malloc(sizeof(char) * (size + 1));
	if (!real)
		return (0);
	ft_rev(arr, size);
	ft_strncpy(real, arr, size);
	return (real);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;

	i = ft_atoi_base(nbr, base_from);
	if (i == -1)
		return (NULL);
	return (ft_putnbr_base(i, base_to));
}
