/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:51:46 by ggeri             #+#    #+#             */
/*   Updated: 2020/01/31 18:07:57 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

void	iso(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(30 * 3.14 / 180);
	*y = (*x + *y) * sin(30 * 3.14 / 180) - z;
}

void	draw_line(float x1, float y1, t_map *map)
{
	float	x_size;
	float	y_size;
	int		max;
	int		z;
	int		z1;

	map->scale = 30;
	z = map->z[(int)map->coords[0]][(int)map->coords[1]];
	z1 = map->z[(int)y1][(int)x1];
	map->coords[0] *= map->scale;
	map->coords[1] *= map->scale;
	x1 *= map->scale;
	y1 *= map->scale;
	map->colour = (z) ? 0xe80c0c : 0xffffff;
	iso(&(map->coords[0]), &(map->coords[1]), z);
	iso(&x1, &y1, z1);
	map->coords[0] += map->key_x;
	x1 += map->key_x;
	map->coords[1] += map->key_y;
	y1 += map->key_y;
	x_size = x1 - map->coords[0];
	y_size = y1 - map->coords[1];
	max = find_max(find_mod(x_size), find_mod(y_size));
	x_size /= max;
	y_size /= max;
	while ((int)(map->coords[0] - x1) || (int)(map->coords[1] - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->coords[0], map->coords[1], map->colour);
		map->coords[0] += x_size;
		map->coords[1] += y_size;
		printf("!!!!!!(%f;%f) && size: %f,%f\n", map->coords[0], map->coords[1], x_size, y_size);
	}
	printf("----(%f;%f) && size: %f,%f\n", map->coords[0], map->coords[1], x_size, y_size);
}

void	draw(t_map *map)
{
	//int		x;
	//int		y;
	(map->coords)[0] = 0;
	(map->coords)[1] = 0;//y
	while (map->coords[1] < map->y)
	{
		printf("Size(%d,%d)\n", map->x, map->y);
		map->coords[0] = 0;//x
		while (map->coords[0] < map->x)
		{
			if (map->coords[0] < map->x - 1)
			{
				printf("1(%f;%f)\n", map->coords[0], map->coords[1]);
				draw_line(map->coords[0] + 1, map->coords[1], map);
				printf("2(%f;%f)\n", map->coords[0], map->coords[1]);
			}
			if (map->coords[1] < map->y - 1)
			{
				printf("3(%f;%f)\n", map->coords[0], map->coords[1]);
				draw_line(map->coords[0], map->coords[1] + 1, map);
				printf("4(%f;%f)\n", map->coords[0], map->coords[1]);
			}
			(map->coords[0])++;
		}
		(map->coords[1])++;
	}
}
