/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jam_min_2 <jam_min_2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:32:06 by jaemikim          #+#    #+#             */
/*   Updated: 2023/11/05 02:11:50 by jam_min_2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if ((*s1 == '\0') || (*s2 == '\0'))
			return ((unsigned char) *s1 - (unsigned char) *s2);
		if ((unsigned char) *s1 != (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
