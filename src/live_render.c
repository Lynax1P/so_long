/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:47:16 by csherill          #+#    #+#             */
/*   Updated: 2021/12/10 01:50:42 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	first(t_general *s, t_temp *ar)
{
	while (ar->x < SIZE_X * s->map.width)
	{
		mlx_put_image_to_window(s->mlx, s->win, s->pers[2].img,
			ar->x, ar->y);
		if (s->map.map[ar->i][ar->j] == '1')
			mlx_put_image_to_window(s->mlx, s->win, s->pers[1].img,
				ar->x, ar->y);
		else
			ft_stone_print(s, ar);
		if (s->map.map[ar->i][ar->j] == 'C')
			mlx_put_image_to_window(s->mlx, s->win, s->pers[3].img,
				ar->x, ar->y);
		else if (s->map.map[ar->i][ar->j] == 'E')
			mlx_put_image_to_window(s->mlx, s->win, s->pers[4].img,
				ar->x, ar->y);
		else if (s->map.map[ar->i][ar->j] == 'V')
			mlx_put_image_to_window(s->mlx, s->win, s->pers[9].img,
				ar->x + 10, ar->y + 20);
		ar->j += 1;
		ar->x += SIZE_X;
	}
	return ;
}

int	move_management(void *s1)
{
	t_general		*s;
	t_temp			ar;

	s = s1;
	ft_null_num((size_t *)&ar.i, (size_t *)&ar.j,
		(size_t *)&ar.x, (size_t *)&ar.y);
	while (ar.y < SIZE_Y * s->map.height)
	{
		ar.x = 0;
		ar.j = 0;
		first(s, &ar);
		ar.i += 1;
		ar.y += SIZE_Y;
	}
	return (0);
}

static void	inside_while(t_general *s, t_temp *ar)
{
	while (ar->x < SIZE_X * s->map.width)
	{
		if ((ar->i >= s->map.pers_y - 1 && ar->i <= s->map.pers_y + 1)
			&& (s->map.pers_x - 1 <= ar->j && s->map.pers_x + 1 >= ar->j))
		{
			if (s->map.map[ar->i][ar->j] == '1')
				write(1, "", 0);
			else
				ft_stone_print(s, ar);
			mlx_put_image_to_window(s->mlx, s->win, s->pers[s->anim.pers].img,
				((s->map.pers_x * SIZE_X) + s->slow.x + s->anim.pers_x),
				((s->map.pers_y * SIZE_Y) + s->slow.y + s->anim.pers_y - 3));
		}
		if (s->map.map[ar->i][ar->j] == 'V')
			mlx_put_image_to_window(s->mlx, s->win, s->pers[9].img,
				ar->x + 10, ar->y + 20);
		else if (s->map.map[ar->i][ar->j] == 'C')
			mlx_put_image_to_window(s->mlx, s->win, s->pers[3].img,
				ar->x, ar->y);
		else if (s->map.map[ar->i][ar->j] == 'E')
			mlx_put_image_to_window(s->mlx, s->win, s->pers[4].img,
				ar->x, ar->y);
		ar->j += 1;
		ar->x += SIZE_X;
	}
}

int	real_render(void *s1)
{
	t_general		*s;
	t_temp			ar;

	s = s1;
	ft_null_num((size_t *)&ar.i, (size_t *)&ar.j, (size_t *)&ar.x,
		(size_t *)&ar.y);
	while (ar.y < SIZE_Y * s->map.height)
	{
		ar.x = 0;
		ar.j = 0;
		inside_while(s, &ar);
		ar.i += 1;
		ar.y += SIZE_Y;
	}
	all_animation(s1);
	return (0);
}
