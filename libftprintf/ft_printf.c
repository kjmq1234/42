/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:18:55 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/23 16:21:36 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	t_data	*info;

	info = (t_data *) calloc(1, sizeof(t_data));
	parse_type(format, info);
}
