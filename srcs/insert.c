/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:08:28 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/02 19:20:48 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lets_insert(char **map, t_pos *tetri, int block)
{
	int	i;

	i = -1;
	while (++i < 4)
		map[tetri[block].y_po + tetri[block].y[i]][tetri[block].x_po
			+ tetri[block].x[i]] = tetri[block].c;
}

void	remove_it(char **map, t_pos *tetri, int block)
{
	int i;

	i = -1;
	while (++i < 4)
		map[tetri[block].y_po + tetri[block].y[i]][tetri[block].x_po
			+ tetri[block].x[i]] = '.';
}
