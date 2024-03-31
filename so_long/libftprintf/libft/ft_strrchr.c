/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:11:03 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 02:45:23 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
