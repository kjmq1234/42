/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:11:03 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/05 02:17:09 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	s += slen;
	while (slen >= 0)
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		slen--;
		s--;
	}
	return (0);
}
