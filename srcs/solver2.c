/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 22:50:58 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/01 23:40:37 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		will_it_fit(char **map, t_pos tetri, int size)
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
				if (map[y][x] == '.')
					if (x == (tetri.x_po + tetri.x[i]) && y == (tetri.y_po + tetri.y[i]))
						j++;
				if (j == 4)
					return (1);
			}
		}
	}
	return (0);
}

void	lets_insert(char **map, t_pos tetri)
{
	int	i;

	i = -1;
	while (++i < 4)
		map[tetri.y_po + tetri.y[i]][tetri.x_po + tetri.x[i]] = tetri.c;
}

void	remove_it(char **map, t_pos tetri)
{
	int i;

	i = -1;
	while (++i < 4)
		map[tetri.y_po + tetri.y[i]][tetri.x_po + tetri.x[i]] = '.';
}

int		where_to(t_pos *tetri,int block, int size)
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

int		solver(t_pos *tetri, int size, char **map, int block)
{
	while (!(will_it_fit(map, tetri[block], size)))
	{
		if (!(where_to(tetri, block, size)))
		{
			if (block == 0)
			{
				printf("size [%d]\n", size);
				ft_memdel((void**)map);
				size++;
				map = map_size(size);
			}
			else
			{
				block--;
				remove_it(map, tetri[block]);
				where_to(tetri, block, size);
			}
			return (solver(tetri, size, map, block));
		}
	}
	lets_insert(map, tetri[block]);
	// for (int i=0; i < size; i++)
	//	printf("%s\n", map[i]);
	// printf("\n");
	block++;
	if (tetri[block].c == '\0')
	{
	for (int i=0; i < size; i++)
		printf("%s\n", map[i]);
	return (1);
	}
	return (solver(tetri, size, map, block));
}
