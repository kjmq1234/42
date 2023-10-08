/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 01:32:00 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/09 16:32:27 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		if ((unsigned char) *s1 > (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		else if ((unsigned char) *s1 < (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
	}
	return (0);
}
