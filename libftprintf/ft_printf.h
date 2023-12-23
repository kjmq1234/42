/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:41:28 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/23 16:21:04 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_data
{
	int	flag;
	int	width;
	int	precision;
	int	type;
	int	left_space;
	int	right_space;
	int	need_siged;
	int	sign;
	int	printbase_16;
	int	zero_cnt;
	int	value_len;
	int	total_len;
}	t_data;

int		ft_printf(const char *format, ...);
int		parse_data(const char *format, t_data *info);
int		istype(char type);

#endif
