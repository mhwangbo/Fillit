/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:02:13 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/02 19:54:09 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

typedef struct	s_pos
{
	char		c;
	int			x[4];
	int			y[4];
	int			x_po;
	int			y_po;
}				t_pos;

int				find_sqrt(int n, int nb);
int				get_size(int size);
int				it_box(char *str);
void			it_box_support(int *x, int *i);
int				block_no(int *str);
int				*block_val(char *str, int i);
t_pos			*ft_valid(int fd, int *blocks);
int				block_link_support(char **split, int i, int j, int count);
char			**block_link(char *str);
t_pos			*struct_malloc(char **str);
void			struct_tetri(char **str, t_pos *tetri);
void			support_two(t_pos *tmp, int *pos, int *i, int *j);
void			struct_tetri_support(t_pos *tmp, int *i, int *h, int *pos);
void			lets_insert(char **map, t_pos *tetri, int block);
void			remove_it(char **map, t_pos *tetri, int block);
char			**map_size(int i);
void			zero_y(t_pos *tetri);
void			zero_x(t_pos *tetri);
int				solver(t_pos *tetri, int *size, char **map, int *block);
int				will_it_fit(char **map, t_pos *tetri, int size, int block);
int				where_to(t_pos *tetri, int block, int size);
int				solver_s(t_pos *tetri, int size, char **map, int block);
void			printer(char **map);

#endif
