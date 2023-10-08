/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:56:03 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/06 21:14:04 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ten_tosixteen(unsigned long long str)
{
	if (str % 16 >= 10)
		return ('a' + (str % 16) - 10);
	else
		return ('0' + (str % 16));
}

void	first(unsigned long long addr)
{
	int		i;
	char	add[16];

	i = 15;
	while (addr / 16 > 0)
	{
		if (addr % 16 >= 10)
			add[i--] = 'a' + (addr % 16) - 10;
		else
			add[i--] = '0' + (addr % 16);
		addr /= 16;
	}
	if (addr % 16 >= 10)
		add[i--] = 'a' + (addr % 16) - 10;
	else
		add[i--] = '0' + (addr % 16);
	while (i != -1)
		add[i--] = '0';
	write(1, add, 16);
	write(1, ": ", 2);
}

void	second(unsigned char *addr, unsigned int size, int n, unsigned int i)
{
	char			buf[2];

	while (i < 16)
	{		
		if (i > size - 16 * n - 1)
			write(1, "  ", 2);
		else
		{
			if (*addr / 16 >= 10)
				buf[0] = *addr / 16 - 10 + 'a';
			else
				buf[0] = *addr / 16 + '0';
			if (*addr % 16 >= 10)
				buf[1] = *addr % 16 - 10 + 'a';
			else
				buf[1] = *addr % 16 + '0';
			addr++;
			write(1, buf, 2);
		}
		if (i++ % 2 == 1)
			write(1, " ", 1);
	}
}

void	third(unsigned char *addr, unsigned int size, int n)
{
	unsigned int	i;
	int				j;

	j = n;
	i = 0;
	while (i < 16)
	{
		if (i > size - 16 * n - 1)
			break ;
		else
		{
			if ((*addr >= 32) && (*addr <= 126))
				write(1, addr, 1);
			else
				write(1, ".", 1);
		}
		addr++;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{	
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (size == 0)
		return ((unsigned char *) addr);
	while (i < size / 16)
	{
		first((unsigned long long) addr + i * 16);
		second((unsigned char *) addr + i * 16, size, i, 0);
		third((unsigned char *) addr + i * 16, size, i);
		write(1, "\n", 1);
		i++;
	}
	first((unsigned long long) addr + i * 16);
	second((unsigned char *) addr + i * 16, size, i, 0);
	third((unsigned char *) addr + i * 16, size, i);
	write(1, "\n", 1);
	return ((unsigned char *) addr);
}
