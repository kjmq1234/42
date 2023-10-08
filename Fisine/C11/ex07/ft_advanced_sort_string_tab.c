/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:04:12 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/08 12:49:02 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ftswap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i + 1] != 0)
	{
		while (tab[j + i + 1] != 0)
		{
			if (((*cmp)(tab[j], tab[j + 1])) > 0)
				ftswap(&tab[j], &tab[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}	
}
