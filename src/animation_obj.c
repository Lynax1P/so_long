/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:50:56 by csherill          #+#    #+#             */
/*   Updated: 2021/12/10 01:23:27 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	anim_pers(t_general *s)
{
	if (s->temp.count == 20)
	{
		s->anim.pers_x += 3;
		s->anim.pers_y += 6;
	}
	if (s->temp.count == 40)
	{
		s->anim.pers_x -= 3;
		s->anim.pers_y -= 6;
	}
	if (s->temp.count == 60)
	{
		s->anim.pers_x -= 3;
		s->anim.pers_y += 6;
	}
	if (s->temp.count == 80)
	{	
		s->anim.pers_x += 3;
		s->anim.pers_y -= 6;
	}
	if (s->temp.count > 80)
		s->temp.count = 0;
}

void	all_animation(void *s1)
{
	t_general	*s;

	s = s1;
	s->temp.count += 1;
	anim_pers(s);
}

void	ft_stone_print(t_general *s, t_temp *ar)
{
	if (ar->i % 2 == 0 || ar->j % 5 == 0)
		mlx_put_image_to_window(s->mlx, s->win, s->pers[2].img, ar->x, ar->y);
	else
		mlx_put_image_to_window(s->mlx, s->win, s->pers[7].img, ar->x, ar->y);
}

void	str_step(t_general *s)
{
	t_temp	temp;

	ft_null_num((size_t *)&temp.i, (size_t *)&temp.j, (size_t *)&temp.k, 0);
	if (s->step == 0)
	{
		s->str[0] = '0';
		s->str[1] = '\0';
	}
	else
	{
		temp.k = s->step;
		while (temp.k != 0)
			temp.k /= 10 + ((temp.i++) * 0);
		s->str[temp.i] = 0;
		temp.j = s->step;
		while (temp.j != 0)
		{
			s->str[--temp.i] = "0123456789"[temp.j % 10];
			temp.j /= 10;
		}
	}
}
