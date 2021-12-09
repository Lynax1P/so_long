/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:48:20 by csherill          #+#    #+#             */
/*   Updated: 2021/12/09 17:12:24 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# define STEP 10
# define SIZE_X	70
# define SIZE_Y	70
//# define COL(r, g, b, a) ((((r) & 0xff) << 16) | (((g) & 0xff) << 8) | 
//((b) & 0xff) | (((a) & 0xff) << 24))
# define COIN		"img/keyYellow.xpm"
# define PLEYER1	"img/blockermad.xpm"
# define PLEYER2	"img/blockerbody.xpm"
# define EXIT		"img/lock_yellow.xpm"
# define STONE		"img/lock_blue.xpm"
# define ENEMIES	"img/slimeWalk1.xpm"
# define ENEMIES1	"img/slimeWalk2.xpm"
# define ENEMIES2	"img/flyFly2.xpm"
# define FON		"img/houseDarkAlt.xpm"
# define FON1		"img/houseDarkAlt2.xpm"
// # define FON1 ""
# define ZERO "./img/number/hud_0.xpm"
# define ONE "./img/number/hud_1.xpm"
# define TWO "./img/number/hud_2.xpm"
# define THREE "./img/number/hud_3.xpm"
# define FOUR "./img/number/hud_4.xpm"
# define FIVE "./img/number/hud_5.xpm"
# define SIX "./img/number/hud_6.xpm"
# define SEVEN "./img/number/hud_7.xpm"
# define EIGHT "./img/number/hud_8.xpm"
# define NINE "./img/number/hud_9.xpm"

typedef struct s_ptr
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		hight;
	int		endian;
	char	**line;
}			t_ptr;

typedef struct s_map
{
	char	**map;
	int		enemies;
	int		height;
	int		width;
	int		empty_area;
	int		player;
	int		pers_x;
	int		pers_y;
	int		item;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		wall;
}			t_map;

typedef struct s_slow
{
	int		x;
	int		y;
	int		horizon[4];
	int		top;
	int		down;
	int		right;
	int		left;
}			t_slow;

typedef struct s_anim
{
	int		pers;
	int		pers_x;
	int		pers_y;
	int		speed_x;
	int		speed_y;
}			t_anim;

typedef struct s_temp
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		n;
	int		x;
	int		y;
	int		count;
	int		temp;
}				t_temp;

typedef struct s_general
{
	void	*mlx;
	void	*win;
	int		count;
	int		coin;
	int		flag;
	int		step;
	char	str[30];
	t_ptr	pers[20];
	t_map	map;
	t_slow	slow;
	t_anim	anim;
	t_temp	temp;
}				t_general;

int			key_release(int k, void *s1);
void		ft_stone_print(t_general *s, t_temp *ar);
void		check_fd(char *argv, void *s);
void		valid_element(t_map *map);
int			key_press(int k, void *s);
int			move_management(void *s1);
int			left_l(t_general *s);
int			right_l(t_general *s);
int			up_l(t_general *s);
int			down_l(t_general *s);
int			real_render(void *s1);
void		str_step(t_general *s);
void		all_animation(void *s1);

#endif
