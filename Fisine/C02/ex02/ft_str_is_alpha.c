/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:52:17 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/26 17:04:20 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str >= 'A') && (*str <= 'Z'))
		{
			str++;
			continue ;
		}
		else if ((*str >= 'a') && (*str <= 'z'))
		{
			str++;
			continue ;
		}
		else
			return (0);
		str++;
	}
	return (1);
}
