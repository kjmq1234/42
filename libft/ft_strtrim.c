/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:16:02 by jam_min_2         #+#    #+#             */
/*   Updated: 2023/11/03 00:16:36 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				isset(char s, char const *set);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
char			*ft_strdup(const char *s1);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char const	*s2;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	s2 = s1;
	while (isset(*s1, set))
		s1++;
	while ((*s2 != '\0'))
		s2++;
	s2--;
	while (isset(*s2, set))
		s2--;
	if ((s1 > s2) || (*s1 == '0'))
		return (ft_strdup(""));
	str = (char *) malloc(sizeof(char) * (s2 - s1 + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s2 - s1 + 2);
	return (str);
}

int	isset(char s, char const *set)
{
	while (*set != '\0')
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}
