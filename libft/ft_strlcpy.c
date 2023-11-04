/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:19:45 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/05 02:06:39 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i + 1 < dstsize) && (*src != '\0'))
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (dstsize != 0)
		*dst = '\0';
	while (*src != '\0')
	{
		i++;
		src++;
	}
	return (i);
}
