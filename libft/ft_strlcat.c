/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:58:36 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/05 02:06:44 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst += dstlen;
	while ((dstlen + i + 1 < dstsize) && (*src != '\0'))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	if (dstlen > dstsize)
		return (dstsize + srclen);
	else
		return (dstlen + srclen);
}
