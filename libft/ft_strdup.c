/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:16:53 by jaemikim          #+#    #+#             */
/*   Updated: 2023/10/30 02:29:57 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(const char *s);

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
