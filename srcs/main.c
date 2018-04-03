/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:55:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/02 19:14:49 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				find_sqrt(int n, int nb)
{
	if (n * n > nb)
		return (0);
	if (n * n == nb)
		return (n);
	else
		return (find_sqrt(n + 1, nb));
}

int				get_size(int size)
{
	unsigned int	i;

	size *= 4;
	i = 0;
	while (!i)
	{
		i = find_sqrt(1, size);
		size++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	t_pos	*lst;
	char	**map;
	int		blocks;
	int		size;

	map = NULL;
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
		size = get_size(blocks);
		map = map_size(size);
		solver_s(lst, size, map, 0);
	}
	return (0);
}
