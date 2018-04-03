/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:04:48 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/02 19:21:23 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	zero_y(t_pos *tetri)
{
	int	i;
	int	no;

	no = 5;
	i = -1;
	while (++i < 4)
	{
		if (tetri->y[i] < no)
			no = tetri->y[i];
	}
	i = -1;
	while (++i < 4)
		tetri->y[i] -= no;
}

void	zero_x(t_pos *tetri)
{
	int	i;
	int	no;

	no = 5;
	i = -1;
	while (++i < 4)
	{
		if (tetri->x[i] < no)
			no = tetri->x[i];
	}
	i = -1;
	while (++i < 4)
		tetri->x[i] -= no;
}

char	**map_size(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (i < size)
	{
		j = 0;
		if (!(map[i] = ft_memalloc(sizeof(char) * (size + 1))))
			return (0);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}
