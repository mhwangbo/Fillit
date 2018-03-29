/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 04:51:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/28 15:48:25 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*block_val(char *str, int i)
{
	int		*vali;
	int		j;

	j = 0;
	vali = ft_memalloc(4);
	while (j < i)
	{
		if (str[j] == '.')
			vali[0] = vali[0] + 1;
		else if (str[j] == '#')
			vali[1] = vali[1] + 1;
		else if (str[j] == '\n')
		{
			if (str[j + 1] == '\n' || str[j + 1] == '\0')
				j++;
			vali[2] = vali[2] + 1;
		}
		j++;
	}
	return (vali);
}

static int		block_no(int *str)
{
	if (str[0] % 12 != 0 || str[1] % 4 != 0 || str[2] % 4 != 0)
		return (0);
	else
		return (str[1] / 4);
}

static int		it_box(char *str)
{
	int i;
	int row;
	int col;

	i = -1;
	row = 0;
	col = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n' && ++row == 4)
		{
			row = -1;
			col++;
		}
		else if (row == 4 && str[i] != '\n')
			return (0);
		if (str[i] == '\n' && col == 4)
		{
			if (str[i + 1] != '\n' && str[i + 1] != '\0')
				return (0);
			col = 0;
			i++;
		}
	}
	return (1);
}

t_pos			*ft_valid(int fd, int *blocks)
{
	char	buff[550];
	int		*valid;
	int		i;
	char	**split;

	i = read(fd, buff, 550);
	if (i != 0)
	{
		valid = block_val(buff, i);
		*blocks = block_no(valid);
		if (blocks == 0 || it_box(buff) == 0)
			return (NULL);
		else
		{
			if ((split = block_link(buff)) == NULL)
				return (NULL);
			return (struct_malloc(split, *blocks));
		}
	}
	return (NULL);
}
