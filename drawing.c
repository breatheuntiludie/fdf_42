/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:51:46 by ggeri             #+#    #+#             */
/*   Updated: 2020/01/29 20:53:38 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	find_max(float x_size, float y_size)
{
	if (x_size > y_size)
		return (x_size);
	else
		return (y_size);
}

float	find_mod(float x_size)
{
	if (x_size < 0)
		x_size *= -1;
	else
		x_size *= 1;
	return (x_size);
}

void	draw_line(float x, float y, float x1, float y1, t_map *map)
{
	float	x_size;
	float	y_size;
	int		max;
	int		z;
	int		z1;

	z = map->z[(int)x][(int)y];
	z1 = map->z[(int)x1][(int)y1];
	x_size = x1 - x;
	y_size = y1 - y;
	max = find_max(find_mod(x_size), find_mod(y_size));
	x_size /= max;
	y_size /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xffffff);
		x += x_size;
		y += y_size;
	}
}

void	draw(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (x < map->x -1)
				draw_line(x, y, x + 1, y, map);
			if (y < map->y - 1)
				draw_line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
