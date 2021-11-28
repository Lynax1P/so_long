/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:48:20 by csherill          #+#    #+#             */
/*   Updated: 2021/11/28 22:23:51 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>


#define trete return
#define COL(r, g, b, a) ((((r) & 0xff) << 16) | (((g) & 0xff) << 8) | ((b) & 0xff) | (((a) & 0xff) << 24))

typedef struct	s_ptr 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		hight;
	int		endian;
	char	**line;
}				t_ptr;

typedef struct  s_map
{
	char	**map;
	int		height;
	int		width;
	int		empty_area;
	int		player;
	int		pers_x;
	int		pers_y;
	int		item;
	int		exit;
	int		wall;
}			t_map;

typedef struct  s_general
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_ptr	pers;
	t_map	map;

}				t_general;

void		check_fd(char *argv, void *s);
void		valid_element(t_map *map);

#endif
