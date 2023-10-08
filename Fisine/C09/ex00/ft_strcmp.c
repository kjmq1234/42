/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:10 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/06 15:22:23 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		if ((unsigned char) *s1 > (unsigned char) *s2)
			return (*s1 - *s2);
		else if ((unsigned char) *s1 < (unsigned char) *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
