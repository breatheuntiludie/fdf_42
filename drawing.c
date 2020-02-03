/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:51:46 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/03 19:43:40 by ggeri            ###   ########.fr       */
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

int	make_color(float z, t_map *map)
{
	float h_red;
	float h_gb;
	int part_red;
	int part_gb;
	//z /= SCALE;

	h_red = (float)(map->max_z - map->min_z) / 23 * SCALE;
	h_gb = (float)(map->max_z - map->min_z) / 243 * SCALE;

	z = (map->min_z < 0) ? z + map->min_z : z;
	part_red = (map->max_z - map->min_z) ? (z / h_red) : z;
	part_gb = (map->max_z - map->min_z) ? (z / h_gb) : z;
	return ( 0xffffff - part_red * 0x010000 - part_gb * 0x000101);
}

void	draw_line(float x1, float y1, t_map *map)
{
	float	x_size;
	float	y_size;
	float		z;
	float		z1;
	float 		z_0;
	float	x;
	float	y;
	float	t;

	x = map->x_s;
	y = map->y_s;
	z = map->z[(int)y][(int)x] * SCALE;
	z1 = map->z[(int)y1][(int)x1] * SCALE;
	scaling(&x, &y, &x1, &y1);

	//map->colour = (z) ? 0xff6600 : 0xffffff;

	iso(&x, &y, z, map);
	iso(&x1, &y1, z1, map);
	rot_x(&x, &y, z, map);
	rot_x(&x1, &y1, z1, map);
	rot_y(&x, &y, z, map);
	rot_y(&x1, &y1, z1, map);
	rot_z(&x, &y, z, map);
	rot_z(&x1, &y1, z1, map);
	move(&x, &x1, map->key_x);
	move(&y, &y1, map->key_y);
	z_0 = z;
	if (z > z1)
	{
		z = z1;
		z1 = z_0;
		z_0 = z;


		t = x;
		x = x1;
		x1 = t;

		t = y;
		y = y1;
		y1 = t;
		t = y1;

	}
	x_size = x1 - x;
	y_size = y1 - y;
	local(&x_size, &y_size);
	t = y;

	map->colour = make_color(z, map);
	while ((int)(x - x1) || (int)(y - y1))
	{
		//z = (y1 > t) ? (z1 - z_0) * ((y - t) / (y1 - t)) : (z_0 - z1) * ((y - t) / (y1 - t));  0xe80c0c
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, map->colour);
		//z = (z1 - z_0) * ((y - t) / (y1 - t));
		z = (z1 - z_0) * ((y - t) / (y1 - t));
		if (z1 != z_0)
			map->colour = make_color(z, map);
		else
			map->colour = make_color(z_0,map);
		x += x_size;
		y += y_size;
	}
}


void	draw(t_map *map)
{
	place_menu(map);
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
