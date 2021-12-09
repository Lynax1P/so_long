/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:37:02 by csherill          #+#    #+#             */
/*   Updated: 2021/12/10 01:19:54 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	swap_el_mas(t_general *s, int x, int y, int *nul)
{
	t_temp	temp;

	*nul = 0;
	temp.l = s->map.pers_x - x;
	temp.n = s->map.pers_y - y;
	if (s->map.map[temp.n][temp.l] == 'C')
		s->coin += 1;
	if (s->coin == s->map.item)
		s->map.map[s->map.exit_y][s->map.exit_x] = 'E';
	if (s->map.map[temp.n][temp.l] == 'E')
		exit(0);
	else if (s->map.map[temp.n][temp.l] == 'V')
		ft_error("Dead");
	s->map.map[s->map.pers_y][s->map.pers_x] = '0';
	s->map.pers_x = temp.l;
	s->map.pers_y = temp.n;
	s->map.map[s->map.pers_y][s->map.pers_x] = 'P';
	s->count += 1;
	return ;
}

int	left_l(t_general *s)
{
	if ((s->slow.horizon[3] == 1 && s->slow.y < 0 && s->slow.x == 0) || \
	(s->slow.horizon[2] == 1 && s->slow.y > 0 && s->slow.x == 0))
		return (0);
	else if (s->slow.x <= -SIZE_X + (STEP + s->flag))
	{
		swap_el_mas(s, 1, 0, &s->slow.x);
	}
	else if (s->flag && s->slow.left == 0 && s->slow.x < 36)
		s->slow.x -= s->slow.x;
	else
		s->slow.x -= (STEP + s->flag);
	s->anim.pers = 6;
	return (1);
}

int	right_l(t_general *s)
{
	if ((s->slow.horizon[0] == 1 && s->slow.y < 0 && s->slow.x == 0) || \
		(s->slow.horizon[1] == 1 && s->slow.y > 0 && s->slow.x == 0))
		return (0);
	else if (s->slow.x >= SIZE_X - (STEP + s->flag))
	{
		swap_el_mas(s, -1, 0, &s->slow.x);
		s->slow.x = 0;
	}
	else if (s->flag && s->slow.right == 0 && s->slow.x < -36)
		s->slow.x += s->slow.x;
	else
		s->slow.x += (STEP + s->flag);
	s->anim.pers = 6;
	return (1);
}

int	up_l(t_general *s)
{
	if ((s->slow.horizon[3] == 1 && s->slow.x < 0 && s->slow.y == 0) || \
		(s->slow.horizon[0] == 1 && s->slow.x > 0 && s->slow.y == 0))
		return (0);
	else if (s->slow.y <= -SIZE_Y + (STEP + s->flag))
		swap_el_mas(s, 0, 1, &s->slow.y);
	else if (s->flag && s->slow.top == 0 && s->slow.y < 36)
		s->slow.y -= s->slow.y;
	else
		s->slow.y -= (STEP + s->flag);
	s->anim.pers = 5;
	return (1);
}

int	down_l(t_general *s)
{
	if ((s->slow.horizon[1] == 1 && s->slow.x > 0 && s->slow.y == 0) || \
		(s->slow.horizon[2] == 1 && s->slow.x < 0 && s->slow.y == 0))
		return (0);
	else if (s->slow.y >= SIZE_Y - (STEP + s->flag))
		swap_el_mas(s, 0, -1, &s->slow.y);
	else if (s->flag && s->slow.top == 0 && s->slow.y < -36)
		s->slow.y += s->slow.y;
	else
		s->slow.y += (STEP + s->flag);
	s->anim.pers = 5;
	return (1);
}
