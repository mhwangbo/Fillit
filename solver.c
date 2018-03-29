/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 00:04:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/28 22:33:31 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	remove_alpha(t_pos tetri, char **map, int size)
{
	int	x;
	int	y;
	int	x_tmp;
	int	y_tmp;

	y = -1;
	x_tmp = 800;
	y_tmp = 800;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (map[y][x] == tetri.c)
			{
				if (x_tmp > x)
					x_tmp = x;
				if (y_tmp > y)
					y_tmp = y;
				map[y][x] = '.';
				tetri.x_po = x_tmp;
				tetri.y_po = y_tmp;
			}
		}
	}
}

static int		pos_move(t_pos *tetri, char **map, int size, int loc)
{
	int	x;
	int	y;
	int	i;

	x = tetri[loc].x_po;
	y = tetri[loc].y_po;
	i = 0;
	while (i < 4)
	{
		if (((y + tetri[loc].y[i]) < size) && ((x + tetri[loc].x[i]) < size)
				&& (map[y + tetri[loc].y[i]][x + tetri[loc].x[i]] != '\0'))
			if (map[y + tetri[loc].y[i]][x + tetri[loc].x[i]] == '.')
			{
				map[y + tetri[loc].y[i]][x + tetri[loc].x[i]] = tetri[loc].c;
				i++;
				if (i == 4)
					return (1);
			}
			else
				return (0);
		else
			return (0);
	}
	return (1);
}

static	int		check_pos(t_pos *tetri, char **map, int size, int *loc)
{
	if (tetri[*loc].x_po == (size - 1))
	{
		if (tetri[*loc].y_po == (size - 1))
		{
			remove_alpha(tetri[*loc], map, size);
			if (*loc != 0)
			{
				tetri[*loc].y_po = 0;
				tetri[*loc].x_po = 0;
				*loc -= 1;
			}
			else
				return (0);
			check_pos(tetri, map, size, loc);
			return (0);
		}
		else
		{
			remove_alpha(tetri[*loc], map, size);
			tetri[*loc].x_po = 0;
			tetri[*loc].y_po += 1;
			return (1);
		}
	}
	else
	{
		remove_alpha(tetri[*loc], map, size);
		tetri[*loc].x_po += 1;
		return (1);
	}
}

int				receive_solver(t_pos *tetri, char **map, int loc, int size, int blocks)
{
	if (loc == 0 && tetri[loc].x_po == (size - 1) && tetri[loc].y_po == (size - 1))
	{
		map = map_size(++size);
		tetri[0].x_po = 0;
		tetri[0].y_po = 0;
	}
	if (pos_move(tetri, map, size, loc) == 0)
		while (check_pos(tetri, map, size, &loc) == 1)
		{
			if (pos_move(tetri, map, size, loc) == 1)
			{
				if (loc == (blocks - 1))
					return (1);
				loc++;
				break ;
			}
		}
	else
	{
		if (loc == (blocks - 1))
			return (1);
		loc++;
	}
	receive_solver(tetri, map, loc, size, blocks);
	return (0);
}
