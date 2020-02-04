/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:06:55 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/03 19:48:54 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_map *map)
{
	map->key_x = 0;
	map->key_y = 0;
	map->code = 0;
	map->rot_x = 0;
	map->angle_x = 0;
	map->rot_y = 0;
	map->angle_y = 0;
	map->rot_z = 0;
	map->angle_z = 0;
}

void	change_mod(t_map *map)
{
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->code = !(map->code);
}

int		change_iso(int key, t_map *map)
{
	if (key == 69)
		change_mod(map);
	if (key == 15)
		reset(map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int		press_key_0(int key, t_map *map)
{
	if (key == 7)
	{
		map->rot_x = 1;
		map->angle_x += 5;
	}
	if (key == 16)
	{
		map->rot_y = 1;
		map->angle_y += 5;
	}
	if (key == 6)
	{
		map->rot_z = 1;
		map->angle_z += 5;
	}
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (0);
}

int		press_key(int key, t_map *map)
{
	press_key_0(key, map);
	if (key == 126)
		map->key_y -= MOVE;
	if (key == 125)
		map->key_y += MOVE;
	if (key == 124)
		map->key_x += MOVE;
	if (key == 123)
		map->key_x -= MOVE;
	if (key == 48 && map->code == 0)
	{
		map->key_y = SIZE / 2 - map->y * SCALE / 2;
		map->key_x = SIZE / 2 - map->x * SCALE / 2;
	}
	if (key == 48 && map->code == 1)
	{
		change_mod(map);
		map->key_y = SIZE / 2 - map->y * SCALE / 2;
		map->key_x = SIZE / 2 - map->x * SCALE / 2;
		change_mod(map);
	}
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}
