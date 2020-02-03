/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:06:55 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/02 14:43:19 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int		change_iso(int key, t_map *map)
{
	int		c=0;

	if (key == 78)
		map->code = PROJECTION;
	if (key == 69)
		map->code = 0;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);

}

int		press_key(int key, t_map *map)
{
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