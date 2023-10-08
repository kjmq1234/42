/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:42:30 by jaemikim          #+#    #+#             */
/*   Updated: 2023/07/20 23:02:50 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	printf("-ex06_test_case-\n\n");
	char *str = "Hello";
	printf("input : Hello\n");
	printf("your answer : %d", ft_strlen(str));
	printf("\n\n------------------------------\n\n");
}
*/
