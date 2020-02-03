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

# include "fdf.h"

// int		mouse(int key, t_map *map)
// {
// 	if (key == 1)
// 	{
// 		map->rot_x = 1;
// 		map->angle += 5;
// 	}
// 	return (0);
// }

int		change_iso(int key, t_map *map)
{
	if (key == 78)
		map->code = PROJECTION;
	if (key == 69)
		map->code = 0;
	if (key == 15)
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
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int		press_key(int key, t_map *map)
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
		mlx_destroy_window (map->mlx_ptr, map->win_ptr);
		exit(0);
	}
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
		map->key_y = SIZE / 2;
		map->key_x = SIZE / 2;
	}
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}
