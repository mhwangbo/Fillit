/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:33:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/02 19:18:08 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		block_link_support(char **split, int i, int j, int count)
{
	int	k;

	k = 0;
	if (split[i][j + 1] == '#')
		k++;
	if (split[i][j - 1] == '#')
		k++;
	if (count != 0 && split[i - 1][j] == '#')
		k++;
	if (count != 3 && split[i + 1][j] == '#')
		k++;
	return (k);
}

char	**block_link(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	split = ft_strsplit(str, '\n');
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] == '#')
				k += block_link_support(split, i, j, (i % 4));
		}
		if (i % 4 == 3)
		{
			if (k != 6 && k != 8)
				return (NULL);
			k = 0;
		}
	}
	return (split);
}
