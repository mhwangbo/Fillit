/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:55:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/31 19:59:23 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_pos	*lst;
	char	**map;
	int		blocks;
	int		size;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (!(lst = ft_valid(open(argv[1], O_RDONLY), &blocks)))
	{
		ft_putstr("error\n");
		return (1);
	}
	else
	{
		size = 2;
		map = map_size(size);
		receive_solver(lst, map, 0, size, blocks);
	}
	return (0);
}
