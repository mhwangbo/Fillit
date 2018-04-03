/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 04:51:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/02 19:35:07 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*block_val(char *str, int i)
{
	int		*vali;
	int		j;

	j = 0;
	vali = (int*)malloc(sizeof(int) * 4);
	ft_memset((void*)vali, 0, 4);
	while (j < i)
	{
		if (str[j] == '.')
			vali[0] = vali[0] + 1;
		else if (str[j] == '#')
			vali[1] = vali[1] + 1;
		else if (str[j] == '\n')
		{
			if (str[j + 1] == '\0')
				vali[2] = vali[2] + 1;
			vali[2] = vali[2] + 1;
		}
		j++;
	}
	return (vali);
}

int		block_no(int *str)
{
	int	i;

	if (str[0] % 12 != 0 || str[1] % 4 != 0 || str[2] % 5 != 0)
		return (0);
	else
	{
		i = str[0] / 12;
		return (i);
	}
}

void	it_box_support(int *x, int *i)
{
	*x = 0;
	*i += 1;
}

int		it_box(char *str)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '.' || str[i] == '#')
		{
			if (++x == 4 && str[i + 1] == '\n')
			{
				it_box_support(&x, &i);
				if (++y == 4 && str[i + 1] == '\n')
					it_box_support(&y, &i);
				else if (y == 4 && str[i + 1] == '\0')
					return (1);
			}
		}
		else
			return (0);
	return (0);
}

t_pos	*ft_valid(int fd, int *blocks)
{
	char	buff[550];
	int		i;
	char	**split;

	i = read(fd, buff, 550);
	if (i != 0)
	{
		*blocks = block_no(block_val(buff, i));
		if (*blocks == 0 || it_box(buff) == 0)
		{
			return (NULL);
		}
		else
		{
			if ((split = block_link(buff)) == NULL)
				return (NULL);
			return (struct_malloc(split));
		}
	}
	return (NULL);
}
