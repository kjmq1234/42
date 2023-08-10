/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsyu <seungsyu@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:05:59 by seungsyu          #+#    #+#             */
/*   Updated: 2023/07/23 13:32:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	top_bot(int x);
void	center(int x, int y);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	if (y <= 0 || x <= 0)
		return ;
	top_bot(x);
	center(x, y);
	if (y >= 2)
		top_bot(x);
}

void	top_bot(int x)
{
	int	i;

	i = 0;
	while (i != x)
	{
		if (i == 0)
			ft_putchar('o');
		else if (i == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
		i++;
	}
	ft_putchar('\n');
}

void	center(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y - 2)
	{
		ft_putchar('|');
		if (x != 1)
		{
			while (j < x - 2)
			{
				ft_putchar(' ');
				j++;
			}
			j = 0;
			ft_putchar('|');
		}
		ft_putchar('\n');
		i++;
	}
}
