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

int		press_key(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window (map->mlx_ptr, map->win_ptr );
		exit(0);
	}
	if (key == 126)
		map->key_y -= 20;
	if (key == 125)
		map->key_y += 20;
	if (key == 124)
		map->key_x += 20;
	if (key == 123)
		map->key_x -= 20;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}
