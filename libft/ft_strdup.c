/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:16:53 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/04 23:26:36 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*tmp;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	tmp = str;
	while (*s1 != '\0')
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (tmp);
}
