/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 22:50:58 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/02 19:26:25 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		will_it_fit(char **map, t_pos *tetri, int size, int block)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = -1;
	j = 0;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			i = -1;
			while (++i < 4)
			{
				if (x == (tetri[block].x_po + tetri[block].x[i]) && y ==
						(tetri[block].y_po + tetri[block].y[i]))
					if (map[y][x] == '.')
						j++;
				if (j == 4)
					return (1);
			}
		}
	}
	return (0);
}

int		where_to(t_pos *tetri, int block, int size)
{
	if (tetri[block].y_po == (size - 1) && tetri[block].x_po == (size - 1))
	{
		tetri[block].y_po = 0;
		tetri[block].x_po = 0;
		return (0);
	}
	else if (tetri[block].x_po == (size - 1))
	{
		tetri[block].x_po = 0;
		tetri[block].y_po = tetri[block].y_po + 1;
		return (1);
	}
	else
	{
		tetri[block].x_po = tetri[block].x_po + 1;
	}
	return (1);
}

int		solver(t_pos *tetri, int *size, char **map, int *block)
{
	while (!(will_it_fit(map, tetri, *size, *block)))
	{
		if (!(where_to(tetri, *block, *size)))
		{
			if (*block == 0)
				return (2);
			else
			{
				*block -= 1;
				remove_it(map, tetri, *block);
				where_to(tetri, *block, *size);
			}
			return (0);
		}
	}
	lets_insert(map, tetri, *block);
	*block += 1;
	if (tetri[*block].c == '\0')
	{
		return (1);
	}
	return (0);
}

int		solver_s(t_pos *tetri, int size, char **map, int block)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		i = solver(tetri, &size, map, &block);
		if (i == 2)
		{
			ft_memdel((void**)map);
			size += 1;
			map = map_size(size);
			i = 0;
		}
	}
	printer(map);
	return (1);
}
