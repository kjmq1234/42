/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsyu <seungsyu@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:13:24 by seungsyu          #+#    #+#             */
/*   Updated: 2023/07/24 20:56:38 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		ft_str_makeint(char *str);

int	main(int argc, char **args)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (argc == 3)
	{
		x = ft_str_makeint(args[1]);
		y = ft_str_makeint(args[2]);
	}
	rush(x, y);
	return (0);
}

int	ft_str_makeint(char *str)
{
	long long int		ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - 48);
		str ++ ;
	}
	if (*str != '\0' || ret > 2147483647)
	{
		return (0);
	}
	return ((int)ret);
}
