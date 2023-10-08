/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:16:33 by heerpark          #+#    #+#             */
/*   Updated: 2023/08/08 12:20:19 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char *argv[])
{
	int			len;
	char		*dict;
	t_dict		*s_head;
	t_dict		*s_temp;

	s_head = (t_dict *)malloc(sizeof(t_dict));
	len = dict_size("numbers.dict");
	dict = dict_to_str("numbers.dict", len);
	if (my_atoi(argv[argc - 1]) < 0)
		write(1, "Error\n", 6);
	if (!parsing(dict, s_head))
		write(1, "Dict Error\n", 11);
	s_temp = s_head;
	s_temp->key = -1;
	while (s_temp->s_right != NULL)
		s_temp = s_temp->s_right;
	printer(s_temp, my_atoi(argv[argc - 1]));
	free(s_head);
	free(dict);
	return (0);
}
