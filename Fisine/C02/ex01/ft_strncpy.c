/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:05:13 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/30 16:28:07 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*ptr;

	ptr = dest;
	i = 0;
	while ((*src) && (i != n))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	while (i != n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (ptr);
}
