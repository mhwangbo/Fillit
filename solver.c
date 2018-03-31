/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 00:04:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/29 01:19:49 by mhwangbo         ###   ########.fr       */
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
	// printf("loc[%d] x[%d] y[%d]\n", loc, tetri[loc].x_po,tetri[loc].y_po);
	i = 0;
	// printf("i [%d] x: %d y: %d\n", i, (tetri[loc].x[i]), (tetri[loc].y[i]));
	while (i < 4)
	{
		if (((y + tetri[loc].y[i]) < size) &&
			   	((x + tetri[loc].x[i]) < size) &&
			   	(map[y + tetri[loc].y[i]][x + tetri[loc].x[i]] != '\0'))
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
//	for (int i = 0; i < 26; i++)
//	{
//		if (tetri[i].c == '\0')
//			break ;
//		printf("%c\n",tetri[i].c);
//		for (int j = 0; j < 4; j++)
//			printf("%d ", tetri[i].x[j]);
//		printf("\n");
//		for (int j = 0; j < 4; j++)
//			printf("%d ", tetri[i].y[j]);
//		printf("\n");
//		printf("x_po:%d y_po:%d\n", tetri[i].x_po, tetri[i].y_po);
//		printf("\n\n\n");
//	}
//	exit(0);
	if (loc == 0 && tetri[loc].x_po == (size - 1) && tetri[loc].y_po == (size - 1))
	{
		// printf("size x: %d y: %d loc: %d size: %d\n", tetri[loc].x_po, tetri[loc].y_po, loc, size);
		ft_memdel((void**)map);
		map = map_size(++size);
		tetri[0].x_po = 0;
		tetri[0].y_po = 0;
	}
	if (pos_move(tetri, map, size, loc) == 0)
		while (check_pos(tetri, map, size, &loc) == 1)
		{
			/* system("sleep 0.25");
			system("clear"); */
			for (int i = 0; i < size; i++)
				printf("%s\n", map[i]);
			printf("\n");
			if (pos_move(tetri, map, size, loc) == 1)
			{
				// printf("if x: %d y: %d loc: %d size: %d\n",tetri[loc].x_po, tetri[loc].y_po, loc, size);
				if (loc == (blocks - 1))
					return (1);
				loc++;
				tetri[loc].x_po = 0;
				tetri[loc].y_po = 0;
				break ;
			}
		}
	else
	{
		// printf("if x: %d y: %d loc: %d size: %d\n", tetri[loc].x_po, tetri[loc].y_po, loc, size);
			for (int i = 0; i < size; i++)
				printf("%s\n", map[i]);
			printf("\n");
		if (loc == (blocks - 1))
			return (1);
		loc++;
	}
	receive_solver(tetri, map, loc, size, blocks);
	return (0);
}
