/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:02:13 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/29 00:52:10 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_pos
{
	char			c;
	int				x[4];
	int				y[4];
	int				x_po;
	int				y_po;
}					t_pos;

t_pos				*ft_valid(int fd, int *blocks);
char				**block_link(char *str);
t_pos				*struct_malloc(char **str);
char				**map_size(int i);
void				zero_y(t_pos *tetri);
void				zero_x(t_pos *tetri);
int					solver(t_pos *tetri, int size, char **map, int block);
int					will_it_fit(char **map, t_pos tetri, int size);
void				lets_insert(char **map, t_pos tetri);
void				remove_it(char **map, t_pos tetri);
int					where_to(t_pos tetri, int size);

#endif
