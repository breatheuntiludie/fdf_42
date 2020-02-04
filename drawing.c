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
	return (x_size > y_size) ? x_size : y_size;
}

static float	find_mod(float x_size)
{
	return (x_size < 0) ? (x_size * (-1)) : x_size;
}

static void		local(float *x_size, float *y_size)
{
	int max;

	max = find_max(find_mod(*x_size), find_mod(*y_size));
	*x_size /= max;
	*y_size /= max;
}

int				mk_col(float z, t_map *map)
{
	float	h_red;
	float	h_gb;
	int		part_red;
	int		part_gb;

	h_red = (float)(map->max_z - map->min_z) / 23 * SCALE;
	h_gb = (float)(map->max_z - map->min_z) / 243 * SCALE;
	z = (map->min_z < 0) ? z + map->min_z : z;
	part_red = (map->max_z - map->min_z) ? (z / h_red) : z;
	part_gb = (map->max_z - map->min_z) ? (z / h_gb) : z;
	return (0xffffff - part_red * 0x010000 - part_gb * 0x000101);
}

void			ft_swap(float *num_0, float *num_1)
{
	float num_2;

	num_2 = *num_0;
	*num_0 = *num_1;
	*num_1 = num_2;
}

t_dpoint		init_pts(float x, float x1, float y, float y1)
{
	t_dpoint pts;

	pts.x = x;
	pts.y = y;
	pts.x1 = x1;
	pts.y1 = y1;
	return (pts);
}

void			init_z(float z, float z1, t_dpoint *pts)
{
	pts->z = z * SCALE;
	pts->z1 = z1 * SCALE;
}

void			make_all_pts(t_map *map, t_dpoint *pts)
{
	scaling(&pts->x, &pts->y, &pts->x1, &pts->y1);
	iso(&pts->x, &pts->y, pts->z, map);
	iso(&pts->x1, &pts->y1, pts->z1, map);
	rot_x(&pts->x, &pts->y, pts->z, map);
	rot_x(&pts->x1, &pts->y1, pts->z1, map);
	rot_y(&pts->x, &pts->y, pts->z, map);
	rot_y(&pts->x1, &pts->y1, pts->z1, map);
	rot_z(&pts->x, &pts->y, pts->z, map);
	rot_z(&pts->x1, &pts->y1, pts->z1, map);
	move(&pts->x, &pts->x1, map->key_x);
	move(&pts->y, &pts->y1, map->key_y);
	if (pts->z > pts->z1)
	{
		ft_swap(&pts->z, &pts->z1);
		ft_swap(&pts->x, &pts->x1);
		ft_swap(&pts->y, &pts->y1);
	}
}

void			draw_line(float x1, float y1, t_map *map)
{
	float		x_size;
	float		y_size;
	float		z_0;
	float		y_0;
	t_dpoint	pts;

	pts = init_pts(map->x_s, x1, map->y_s, y1);
	init_z(map->z[(int)pts.y][(int)pts.x], map->z[(int)y1][(int)x1], &pts);
	make_all_pts(map, &pts);
	x_size = pts.x1 - pts.x;
	y_size = pts.y1 - pts.y;
	local(&x_size, &y_size);
	y_0 = pts.y;
	z_0 = pts.z;
	map->colour = mk_col(pts.z, map);
	while ((int)(pts.x - pts.x1) || (int)(pts.y - pts.y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, pts.x, pts.y, map->colour);
		pts.z = (pts.z1 - z_0) * ((pts.y - y_0) / (pts.y1 - y_0));
		map->colour = (pts.z1 != z_0) ? mk_col(pts.z, map) : mk_col(z_0, map);
		pts.x += x_size;
		pts.y += y_size;
	}
}

void			draw(t_map *map)
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
