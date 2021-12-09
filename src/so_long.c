/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:42:45 by csherill          #+#    #+#             */
/*   Updated: 2021/12/10 01:25:43 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(void *s)
{
	(void)s;
	exit(0);
}

t_ptr	creat_img(void *mlx, int x, int y, char *file_name)
{
	t_ptr	s;

	if (file_name)
	{
		s.hight = y;
		s.img = mlx_xpm_file_to_image(mlx, file_name, &x, &y);
		s.addr = mlx_get_data_addr(s.img, &s.bpp, &s.line_length, &s.endian);
	}
	else
	{
		s.hight = y;
		s.img = mlx_new_image(mlx, x, y);
		s.addr = mlx_get_data_addr(s.img, &s.bpp, &s.line_length, &s.endian);
	}
	return (s);
}

void	init_mlx_system(t_general *s)
{
	s->anim.pers = 5;
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, (SIZE_X * s->map.width), \
		(SIZE_Y * s->map.height), "Lilo");
	s->pers[0] = creat_img(&s->mlx, SIZE_X, SIZE_Y, NULL);
	s->pers[1] = creat_img(&s->mlx, SIZE_X, SIZE_Y, STONE);
	s->pers[2] = creat_img(&s->mlx, SIZE_X, SIZE_Y, FON);
	s->pers[3] = creat_img(&s->mlx, SIZE_X, SIZE_Y, COIN);
	s->pers[4] = creat_img(&s->mlx, SIZE_X, SIZE_Y, EXIT);
	s->pers[5] = creat_img(&s->mlx, SIZE_X, SIZE_Y, PLEYER1);
	s->pers[6] = creat_img(&s->mlx, SIZE_X, SIZE_Y, PLEYER2);
	s->pers[7] = creat_img(&s->mlx, SIZE_X, SIZE_Y, FON1);
	s->pers[9] = creat_img(&s->mlx, SIZE_X, SIZE_Y, ENEMIES);
}

void	init_par(t_general *s)
{
	s->slow.x = 0;
	s->slow.y = 0;
	s->temp.count = 0;
	s->coin = 0;
	s->flag = 0;
	s->anim.pers_x = 0;
	s->anim.pers_y = 0;
	s->step = 0;
	s->temp.temp = 0;
}

int	main(int argc, char **argv)
{
	t_general	s;

	if (argc != 2)
		ft_error("Error FILE\n");
	else
		check_fd(argv[1], &s.map);
	init_mlx_system(&s);
	move_management((void *)&s);
	init_par(&s);
	mlx_hook(s.win, 2, 0, key_press, &s);
	mlx_hook(s.win, 3, 0, key_release, &s);
	mlx_hook(s.win, 17, 0, end_game, NULL);
	mlx_loop_hook(s.mlx, real_render, &s);
	mlx_loop(s.mlx);
}
