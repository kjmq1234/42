/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:23:08 by kyumkim           #+#    #+#             */
/*   Updated: 2023/08/10 11:12:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_inp
{
	int		**map;
	int		row;
	int		col;
	char	empty;
	char	obstacle;
	char	full;
	int		x;
	int		y;
	int		size;
}	t_inp;
char	*stdinput(int fd);
char	*vecdup(char *buf, int buf_size);
void	null_check(char *buf, int read_size);
char	**ft_split(char *buff);
char	*putstr(char *str, int idx1, int idx2);
int		how_many_strs(char *str);
void	errprt(void);
void	first_str_check(char *buff, t_inp *inp);
int		strsize(char *str);
void	makearr(char **input, t_inp *inp);
void	rowcolsame(char **input, t_inp *inp);
void	errprt(void);
void	dp(t_inp *map);
void	ar_min(int x, int y, int size, t_inp *map);
void	print(t_inp *map);
int		min(int x, int y, int **map);
void	dodp(int fd);
void	check_valid(t_inp *map);
#endif
