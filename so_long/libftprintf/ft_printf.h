/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:41:28 by jaemikim          #+#    #+#             */
/*   Updated: 2023/12/29 11:06:01 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		parse_info(const char *format, t_data *info, va_list ap);
int		print_val(const char *format, t_data *info, va_list ap);
int		parse_flag(const char *format, t_data *info);
int		isflag(char flag);
int		print_hex(const char *format, t_data *info, va_list ap);
int		print_other(const char *format, t_data *info, va_list ap);
int		istype(const char *format);

#endif