/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parseflag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:54:23 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/29 11:06:31 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flag(const char *format, t_data *info)
{
	int	len;

	len = 0;
	info->hash = 0;
	info->plus = 0;
	info->empty = 0;
	while (isflag(*format))
	{
		if (*format == '#')
			info->hash = 1;
		else if (*format == ' ')
			info->empty = 1;
		else if (*format == '+')
			info->plus = 1;
		format++;
		len++;
	}
	if (((info->hash == 1) && (info->empty == 1)) || \
	((info->hash == 1) && (info->plus == 1)) || \
	((info->plus == 1) && (info->empty == 1)))
		return (-1);
	return (len);
}

int	isflag(char flag)
{
	if ((flag == '#') || (flag == ' ') || (flag == '+'))
		return (1);
	else
		return (0);
}
