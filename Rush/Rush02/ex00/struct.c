/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:58:52 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/06 15:57:35 by heerpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	dlink(t_dict *s_temp, t_dict *s_new, long long dkey)
{
	if (s_temp->s_right == NULL)
	{
		s_temp->s_right = s_new;
		s_new->s_left = s_temp;
	}
	else if (s_temp->s_right->key > dkey)
	{
		s_new->s_right = s_temp->s_right;
		s_new->s_left = s_temp;
		s_temp->s_right->s_left = s_new;
		s_temp->s_right = s_new;
	}
}

void	knot(t_dict *s_temp, t_dict *s_new)
{
	s_new->key = -100;
	while (s_temp->s_right != NULL)
		s_temp = s_temp->s_right;
	s_temp->s_right = s_new;
	s_new->s_left = s_temp;
	s_new->s_right = NULL;
}

void	to_struct(long long dkey, char *dval, t_dict *head)
{
	t_dict	*s_new;
	t_dict	*s_temp;

	s_new = (t_dict *)malloc(sizeof(t_dict));
	s_temp = head;
	if (dval == NULL)
	{
		knot(s_temp, s_new);
		return ;
	}
	s_new->key = dkey;
	s_new->value = dval;
	if (s_temp->s_right == NULL)
	{
		s_temp->s_right = s_new;
		s_temp->s_right->s_left = head;
		return ;
	}
	while (s_temp->key < dkey)
	{
		dlink(s_temp, s_new, dkey);
		s_temp = s_temp->s_right;
	}
}
