/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:55:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/26 17:51:08 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_pos	*lst;
	int		i;

	if (argc != 2)
		return (1);
	if (!(lst = ft_valid(open(argv[1], O_RDONLY))))
	{
		ft_putstr("INVALID TETRIS");
		return (1);
	}
	else
	{
		i = 0;
		while (i < 4)
		{
			printf("%d\n", lst[0].y[i++]);
		}
	}
	return (0);
}
