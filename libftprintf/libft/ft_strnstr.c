/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:32:59 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/05 02:13:13 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

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
