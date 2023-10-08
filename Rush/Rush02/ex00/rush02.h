/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heerpark <heerpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:21:50 by heerpark          #+#    #+#             */
/*   Updated: 2023/08/08 12:20:29 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_dict{
	long long			key;
	char				*value;
	struct s_dict		*s_left;
	struct s_dict		*s_right;
}	t_dict;

long long	dict_size(char *path);
char		*dict_to_str(char *path, long long len);
long long	parsing(char *dict, t_dict *s_head);
long long	is_printable(char a);
long long	my_atoi(char *str);
void		array_reset(char *str, long long size);
char		*str_to_value(char *str);
void		ft_putchr(char *value);
void		printer(t_dict *s_tail, long long nb);
void		to_struct(long long dkey, char *dval, t_dict *s_head);
long long	ch_pkey(long long key, long long *pr_key);
void		init_pk(long long *pr_key);
long long	dict_rule(char *str);
void		dlink(t_dict *s_temp, t_dict *new, long long dkey);
long long	value_check(long long num, long long *arr);
long long	is_valid_key(long long num, long long *pr_key, t_dict *s_head);
long long	is_pravate(long long num, long long *pr_key);
long long	ch_rdunt(t_dict *s_head, long long vkey);
int			len(int ac, char *av[]);

#endif
