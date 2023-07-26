/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:49:49 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/26 16:22:05 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *dest)
{
	int	i;

	i = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	return (i);
}

int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				dest_len;
	int				src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (*dest)
	{
		dest++;
		i++;
	}
	while ((i + 1 < size) && (*src != '\0'))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	if ((unsigned int) dest_len > size)
		return (size + src_len);
	return (dest_len + src_len);
}
