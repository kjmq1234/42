/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 01:21:12 by jaemikim          #+#    #+#             */
/*   Updated: 2023/08/09 16:01:09 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

long long	plus(int num1, int num2);
long long	minus(int num1, int num2);
long long	multiple(int num1, int num2);
long long	division(int num1, int num2);
long long	modulo(int num1, int num2);
void		module(void);
int			ft_strcmp(char *s1, char *s2);
long long	celcul(int num1, int num2, long long (*f)(int, int));
void		ft_putnbr(long long nb);
int			ft_atoi(char *str);
int			operator(int num2, char *oper);

#endif
