/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csherill <csherill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:25:19 by csherill          #+#    #+#             */
/*   Updated: 2021/12/08 15:27:17 by csherill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	p_v(t_map *map, int *i, int j)
{
	if (map->map[*i][j] == 'P')
	{
		if (map->player == 0)
			map->pers_x = j;
		if (map->player == 0)
			map->pers_y = *i;
		else
			ft_error("Pleyer Don't One\n");
		map->player += 1;
	}
	else if (map->map[*i][j] == 'V')
		map->enemies += 0;
	else
		ft_error("Unknown Element");
}

static void	obj_map(t_map *map, int *i)
{
	int		j;

	j = 0;
	while (j < map->width)
	{
		if (map->map[*i][j] == '1')
			map->wall += 1;
		else if (map->map[*i][j] == '0')
			map->empty_area += 1;
		else if (map->map[*i][j] == 'C')
			map->item += 1;
		else if (map->map[*i][j] == 'E')
		{
			map->exit += 1;
			map->exit_y = *i;
			map->exit_x = j;
		}
		else
			p_v(map, i, j);
		j++;
	}
}

static void	valid_obj(t_map *map)
{
	int		i;

	ft_null_num((size_t *)&i, (size_t *)&map->player, \
		(size_t *)&map->empty_area, (size_t *)&map->item);
	ft_null_num((size_t *)&map->exit, (size_t *)&map->wall,
		(size_t *)&map->pers_x, (size_t *)&map->pers_y);
	map->enemies = 0;
	while (i < map->height)
	{
		obj_map(map, &i);
		i++;
	}
	if (map->exit != 1)
		ft_error("No Exit");
	else if (map->item < 1)
		ft_error("No item");
	else if (map->player == 0)
		ft_error("No Player");
	map->map[map->exit_y][map->exit_x] = '1';
}

void	valid_element(t_map *map)
{
	int		i;
	int		j;

	ft_null_num((size_t *)&i, (size_t *)&j, 0, 0);
	if (map->height > 2 && map->width < 3)
		ft_error("width < 3");
	else if (map->height < 3 && map->width > 2)
		ft_error("height < 3");
	else if (map->height < 3 && map->width < 3)
		ft_error("height < 3 and width < 3");
	while (j < map->width)
	{
		if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
			ft_error("No Valid Map\n");
		j++;
	}
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			ft_error("No Valid Map\n");
		i++;
	}
	valid_obj(map);
}
