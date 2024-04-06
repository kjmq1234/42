/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:02:58 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 18:18:32 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*ptr;

	ptr = dst;
	i = 0;
	while (i < n)
	{
		if (dst != src)
		{
			*(unsigned char *) dst = *(unsigned char *) src;
			dst++;
			src++;
		}
		i++;
	}
	return (ptr);
}
