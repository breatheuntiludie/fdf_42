/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:51:46 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/02 20:30:52 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	find_max(float x_size, float y_size)
{
	if (x_size > y_size)
		return (x_size);
	else
		return (y_size);
}

static float	find_mod(float x_size)
{
	if (x_size < 0)
		x_size *= -1;
	else
		x_size *= 1;
	return (x_size);
}

static void		local(float *x_size, float *y_size)
{
	int max;

	max = find_max(find_mod(*x_size), find_mod(*y_size));
	*x_size /= max;
	*y_size /= max;
}

static int		make_color(int z, t_map *map)
{
	int h;
	int p;

	h = (map->max_z - map->min_z) / 16;//16^5
	p = (h) ? z/h : z;
	return (0xff6600 - z * 1048576);
}

void			draw_line(float x1, float y1, t_map *map)
{
	float	size[2];
	int		z;
	int		z1;
	float	x;
	float	y;

	x = map->x_s;
	y = map->y_s;
	z = map->z[(int)y][(int)x];
	z1 = map->z[(int)y1][(int)x1];
	scaling(&x, &y, &x1, &y1);
	map->colour = (z) ? 0xe80c0c : 0xffffff;
	iso(&x, &y, z, map);
	iso(&x1, &y1, z1, map);
	move(&x, &x1, map->key_x);
	move(&y, &y1, map->key_y);
	size[0] = x1 - x;
	size[1] = y1 - y;
	local(&size[0], &size[1]);
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, map->colour);
		stepping(&x, &y, &size[0], &size[1]);
	}
}

void			draw(t_map *map)
{
	map->y_s = 0;
	while (map->y_s < map->y)
	{
		map->x_s = 0;
		while (map->x_s < map->x)
		{
			if (map->x_s < map->x - 1)
				draw_line(map->x_s + 1, map->y_s, map);
			if (map->y_s < map->y - 1)
				draw_line(map->x_s, map->y_s + 1, map);
			(map->x_s)++;
		}
		(map->y_s)++;
	}
}
