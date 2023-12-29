/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:32:59 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/24 02:45:19 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while ((*haystack != '\0') && (len > 0))
	{
		if (*haystack == *needle)
		{
			if (len >= ft_strlen(needle))
			{
				if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
					return ((char *) haystack);
			}
		}
		haystack++;
		len--;
	}
	return (0);
}
