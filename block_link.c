/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:33:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/26 17:37:41 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		block_link_support(char **split, int i, int j, int count)
{
	if (count == 0)
	{
		if (count == 0)
		{
			if (split[i + 1][j] != '#' && split[i][j + 1] != '#'
					&& split[i][j - 1] != '#')
				return (0);
		}
		else if (count == 3)
		{
			count = 0;
			if (split[i - 1][j] != '#' && split[i][j + 1] != '#'
					&& split[i][j - 1] != '#')
				return (0);
		}
		else if (split[i + 1][j] != '#' && split[i - 1][j] != '#'
				&& split[i][j + 1] != '#' && split[i][j - 1] != '#')
			return (0);
	}
	return (1);
}

char			**block_link(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	split = ft_strsplit(str, '\n');
	while (split[i])
	{
		while (split[i][j])
		{
			if (split[i][j] == '#')
			{
				if (block_link_support(split, i, j, count) == 0)
					return (NULL);
			}
			j++;
		}
		i++;
		count++;
	}
	return (split);
}
