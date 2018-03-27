/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:37:45 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/26 17:53:51 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		struct_tetri_support(t_pos *tmp, int *i, int *h, int *pos)
{
	int	y;
	int pos_tmp;
	int i_tmp;

	y = *h;
	pos_tmp = *pos;
	i_tmp = *i;
	i_tmp++;
	if (i_tmp % 4 == 0)
	{
		tmp[y].c = 'A' + y;
		y++;
		pos_tmp = 0;
	}
	*h = y;
	*pos = pos_tmp;
	*i = i_tmp;
}

static void		support_two(t_pos *tmp, int *pos, int *i, int *j)
{
	int pos_tmp;

	pos_tmp = *pos;
	tmp->y[pos_tmp] = *i % 4;
	tmp->x[pos_tmp++] = *j;
	*pos = pos_tmp;
}

static t_pos	*struct_tetri(char **str, t_pos *tetri)
{
	int		i;
	int		j;
	int		h;
	int		pos;
	t_pos	*tmp;

	i = 0;
	pos = 0;
	h = 0;
	tmp = tetri;
	while (str[i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '#')
				support_two(&tmp[h], &pos, &i, &j);
		}
		struct_tetri_support(tmp, &i, &h, &pos);
	}
	return (tetri);
}

t_pos			*struct_malloc(char **str)
{
	t_pos *tetri;

	tetri = (t_pos*)malloc(sizeof(t_pos) * 26);
	return (struct_tetri(str, tetri));
}
