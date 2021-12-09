/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:52:41 by csherill          #+#    #+#             */
/*   Updated: 2021/12/10 02:06:41 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	step(int k, void *s1)
{
	t_general	*s;

	s = s1;
	s->anim.pers = 5;
	if (k == 0 && (s->slow.left * SIZE_X) + s->slow.x > 0)
	{
		if (left_l(s))
			s->step += 1;
	}
	else if (k == 2 && (s->slow.right * SIZE_X) - s->slow.x > 0)
	{
		if (right_l(s))
			s->step += 1;
	}
	else if (k == 13 && (s->slow.top * SIZE_Y) + s->slow.y > 0)
	{
		if (up_l(s))
			s->step += 1;
	}
	if (k == 1 && (s->slow.down * SIZE_Y) - s->slow.y > 0)
		if (down_l(s))
			s->step += 1;
	return (1);
}

void	beam(t_general *s, int i, int j, int count)
{
	while (s->map.map[i][j + count] != '1')
	{
		s->slow.right += 1;
		count++;
	}
	count = 1;
	while (s->map.map[i][j - count] != '1')
	{
		s->slow.left += 1;
		count++;
	}
	count = 1;
	while (s->map.map[i + count][j] != '1')
	{
		s->slow.down += 1;
		count++;
	}
	count = 1;
	while (s->map.map[i - count][j] != '1')
	{
		s->slow.top += 1;
		count++;
	}
}

void	plav_dvig(int k, t_general *s)
{
	int	i;
	int	j;

	ft_null_num((size_t *)&s->slow.left, (size_t *)&s->slow.right,
		(size_t *)&s->slow.top, (size_t *)&s->slow.down);
	ft_null_num((size_t *)&s->slow.horizon[0],
		(size_t *)&s->slow.horizon[3],
		(size_t *)&s->slow.horizon[1], (size_t *)&s->slow.horizon[2]);
	i = s->map.pers_y;
	j = s->map.pers_x;
	beam(s, i, j, 1);
	if (s->map.map[i - 1][j + 1] == '1')
		s->slow.horizon[0] = 1;
	if (s->map.map[i - 1][j - 1] == '1')
		s->slow.horizon[3] = 1;
	if (s->map.map[i + 1][j + 1] == '1')
		s->slow.horizon[1] = 1;
	if (s->map.map[i + 1][j - 1] == '1')
		s->slow.horizon[2] = 1;
	step(k, s);
	str_step(s);
}

int	key_release(int k, void *s1)
{
	t_general	*s;

	s = s1;
	if (k == 53)
		ft_error("ESC");
	if (k == 257 && s->flag == 0)
		s->flag = 25;
	else if (k == 257 && s->flag == 25)
		s->flag = 0;
	return (1);
}

int	key_press(int k, void *s1)
{
	int			i;
	t_general	*s;

	s = s1;
	i = 0;
	plav_dvig(k, s);
	return (1);
}
