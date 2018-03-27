/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:02:13 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/26 17:51:35 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_pos
{
	char			c;
	int				x[4];
	int				y[4];
}					t_pos;
t_pos				*ft_valid(int fd);
char				**block_link(char *str);
t_pos				*struct_malloc(char **str);

#endif
